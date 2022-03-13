#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <cstring>
#include <sstream>
#include <windows.h>
\
using namespace std;

insertion(MYSQL* conn)
{
	int qstate=0;
	stringstream ss;
	string first_name, last_name, mobile, email;
	cout<<"Enter the first name: "<<endl;
	cin>>first_name;
	cout<<"Enter the last name: "<<endl;
	cin>>last_name;
	cout<<"Enter the mobile number: "<<endl;
	cin>>mobile;
	cout<<"Enter the email address: "<<endl;
	cin>>email;
	ss<<"INSERT INTO studentrecord(first_name, last_name, mobile, email) VALUES('"+first_name+"','"+last_name+"','"+mobile+"','"+email+"')";
	string query = ss.str();
	const char* q= query.c_str();
	qstate = mysql_query(conn, q);
	if(qstate==0)
	{
		cout<<"Record Inserted Successfully"<<endl;
	}
	else
	{
		cout<<"Record not inserted"<<endl;
	}
}

display(MYSQL* conn)
{
	MYSQL_ROW row;
	MYSQL_RES* res;
	if(conn)
	{
		int qstate = mysql_query(conn,"SELECT * FROM studentrecord");
		if(!qstate)
		{
			res= mysql_store_result(conn);
			int count= mysql_num_fields(res);
			while(row = mysql_fetch_row(res))
			{
				for(int i=0;i<count;i++)
				{
					cout<<"\t"<<row[i]<<"\t";
				}
				cout<<endl;
			}
		}
	}
}

deletion(MYSQL* conn)
{
	stringstream ss, sss;
	string first_names;
	MYSQL_ROW row;
	MYSQL_RES* res;
	cout<<"Enter the first name of whose record is to be deleted: "<<endl;
	cin>>first_names;
	sss<<"SELECT * FROM studentrecord WHERE first_name='"+first_names+"'";
	string query = sss.str();
	const char* q= query.c_str();
	mysql_query(conn,q);
	res = mysql_store_result(conn);
	int count = mysql_num_fields(res);
	my_ulonglong x=  mysql_num_rows(res);
	if(x==1)
	{
		ss<<"DELETE FROM studentrecord WHERE first_name='"+first_names+"' ";
		string query = ss.str();
		const char* q= query.c_str();
		mysql_query(conn,q);
		cout<<"Only one record found and deleted with the entered first name"<<endl;
	}
	else if(x>=2)
	{
		cout<<x<<" Number of records found with the given first name"<<endl;
		cout<<"Do you want to delete all the record with the name "<<first_names<<"? (Enter either yes or no)"<<endl;
		string choice;
		cin>>choice;
		if(choice=="YES" or "yes" or "Yes")
		{
			ss<<"DELETE FROM studentrecord WHERE first_name = '"+first_names+"'";
			string query = ss.str();
			const char* q= query.c_str();
			mysql_query(conn, q);
			cout<<"Record with name "<<first_names<<" is deleted"<<endl;
		}
		else 
		{
			cout<<"Enter the last name of which you want to delete the record"<<endl;
			string last_names;
			cin>>last_names;
			ss<<"DELETE FROM studentrecord WHERE first_name = '"+first_names+"' AND last_name = '"+last_names+"' ";
			string query = ss.str();
			const char* q= query.c_str();
			mysql_query(conn, q);
			cout<<"Record with name "<<first_names<<" "<<last_names<<" is deleted"<<endl;
		}
	}
	else
	{
		cout<<"Record with first name "<<first_names<<" is not found"<<endl;
	}
}


newdatabase(MYSQL* conn)
{
	string newdatabasen;
	stringstream ss;
	cout<<"Enter the name of the new database: "<<endl;
	cin>>newdatabasen;
	ss<<"CREATE database "+newdatabasen+"";
	string query = ss.str();
	const char* q= query.c_str();
	int qstate=mysql_query(conn,q);
	if(qstate==0)
	{
		cout<<"Database created successfully"<<endl;
	}
	else
	{
		cout<<"Database not created"<<endl;
	}
}


updatedb(MYSQL* conn)
{
	string s;
	stringstream ss;
	cout<<"Select the record that you want to update: "<<"1. First Name  2. Last Name  3. Mobile  4. Email"<<endl;
	int opt;
	cin>>opt;
	if(opt==1)
	{
		cout<<"Enter the first name which you want to update : "<<endl;
		string las_name;
		cin>>las_name;
		string firs_name;
		cout<<"Enter the name you want to update to: "<<endl;
		cin>>firs_name;
		ss<<"UPDATE studentrecord SET first_name='"+firs_name+"' WHERE first_name='"+las_name+"'";
		string query = ss.str();
		const char* q= query.c_str();
		int qstate = mysql_query(conn,q);
		if(qstate==0)
		{
			cout<<"Updated Successfully"<<endl;
		}
		else
		{
			cout<<"Not Updated"<<endl;
		}
	}
	else if(opt==2)
	{
		cout<<"Enter the last name which you want to update : "<<endl;
		string las_name;
		cin>>las_name;
		string firs_name;
		cout<<"Enter the name you want to update to: "<<endl;
		cin>>firs_name;
		ss<<"UPDATE studentrecord SET last_name='"+firs_name+"' WHERE last_name='"+las_name+"'";
		string query = ss.str();
		const char* q= query.c_str();
		int qstate = mysql_query(conn,q);
		if(qstate==0)
		{
			cout<<"Updated Successfully"<<endl;
		}
		else
		{
			cout<<"Not Updated"<<endl;
		}
	}
	else if(opt==3)
	{
		cout<<"Enter the mobile number which you want to update : "<<endl;
		string las_name;
		cin>>las_name;
		string firs_name;
		cout<<"Enter the mobile number you want to update to: "<<endl;
		cin>>firs_name;
		ss<<"UPDATE studentrecord SET mobile='"+firs_name+"' WHERE mobile='"+las_name+"'";
		string query = ss.str();
		const char* q= query.c_str();
		int qstate = mysql_query(conn,q);
		if(qstate==0)
		{
			cout<<"Updated Successfully"<<endl;
		}
		else
		{
			cout<<"Not Updated"<<endl;
		}
	}
	else if(opt==4)
	{
		cout<<"Enter the email which you want to update : "<<endl;
		string las_name;
		cin>>las_name;
		string firs_name;
		cout<<"Enter the email you want to update to: "<<endl;
		cin>>firs_name;
		ss<<"UPDATE studentrecord SET email='"+firs_name+"' WHERE email='"+las_name+"'";
		string query = ss.str();
		const char* q= query.c_str();
		int qstate = mysql_query(conn,q);
		if(qstate==0)
		{
			cout<<"Updated Successfully"<<endl;
		}
		else
		{
			cout<<"Not Updated"<<endl;
		}
	}
	else
	{
		cout<<"Please select the valid option"<<endl;
	}
}


int main() 
{
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "myproject", 3306, NULL, 0);
	if(conn)
	{
	 	cout<<"Connection Successfull"<<endl<<endl;
	 	int choice=-1;
	 	while(1)
	 	{
	 		cout<<endl<<"Please select any of the following to proceed"<<endl<<endl;
	 		cout<<"1.Add New Records"<<endl<<"2.Display Records"<<endl<<"3.Delete Records"<<"\n"<<"4.New Database for Records"<<"\n"<<"5.Update Record"<<"\n"<<"6.Exit"<<endl<<endl;
	 		cin>>choice;
	 		switch (choice)
	 		{
	 			case 1: insertion (conn);
	 					break;
	 			case 2: display(conn);
	 					break;
	 			case 3:	deletion(conn);
	 					break;
	 			case 4: newdatabase(conn);
	 					break;
	 			case 5: updatedb(conn);
	 					break;
	 			case 6: exit(0);
	 			default:
	 				cout<<"Select a valid option"<<endl;
	 		}
	 	}
	}
	else if(!conn)
	{
	 	cout<<"No connection"<<endl;
	}
	return 0;
}
