#include "pch.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include<map>
#include<sstream>  
#include <algorithm>
using namespace std;
//.......................................................................................
struct primarystudentIndex {
	int stId, offset;

};
bool my_cmp(const primarystudentIndex & a, const primarystudentIndex & b)
{
	
	return a.stId< b.stId;
}
void sortStudentprimaryindx(vector<primarystudentIndex> vec, fstream & f) {
	sort(vec.begin(),vec.end(), my_cmp);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].stId << ":" << vec[i].offset << endl;
	}

}
//........................................................................................
struct secondarystudentIndex1{
	string stName;
	int stId;
};
bool my_cmp2(const secondarystudentIndex1 & a, const secondarystudentIndex1 & b)
{

	return a.stName < b.stName;
}
void sortStudentsecondaryindx1(vector<secondarystudentIndex1> vec, fstream & f) {
	sort(vec.begin(), vec.end(), my_cmp2);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].stName << ":" << vec[i].stId<< endl;
	}

}
//.......................................................................................
struct secondarystudentIndex2{
	float stGPA;
	int stId;
};
bool my_cmp3(const secondarystudentIndex2 & a, const secondarystudentIndex2 & b)
{

	return a.stGPA < b.stGPA;
}
void sortStudentsecondaryindx2(vector<secondarystudentIndex2> vec, fstream & f) {
	sort(vec.begin(), vec.end(), my_cmp3);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].stGPA << ":" << vec[i].stId << endl;
	}

}
//...................................................................................
struct secondarystudentIndex3 {
	
	int stId, SDeptId;
};
bool my_cmpo(const secondarystudentIndex3 & a, const secondarystudentIndex3 & b)
{

	return a.SDeptId < b.SDeptId;
}
void sortStudentsecondaryindx3(vector<secondarystudentIndex3> vec, fstream & f) {
	sort(vec.begin(), vec.end(), my_cmpo);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].SDeptId << ":" << vec[i].stId << endl;
	}

}
//...................................................................................
struct StudentRecord {
	
	string StudentName;
	float SGPA;
	int StudentId;
	int SLevel;
	int SDeptId;
};
char binarySearch(string a, int l, int r, char p)
{
if (r >= l) {
		int mid = l + (r - 1) / 2;
		
if (mid % 2 != 0) {

			if (a[mid - 1] == p)
				return a[mid];

			if (a[mid - 1] > p)
				return binarySearch(a, l, mid - 1, p);

			if (a[mid - 1] < p)
				return binarySearch(a, mid, r, p);
			else
				cout << " " << endl;

		

		}
		if (a[mid] == p)
			return a[mid + 1];

		if (a[mid] > p)
			return binarySearch(a, l, mid - 1, p);
		

		if (a[mid] < p)
			return binarySearch(a, mid + 1, r, p);


	}
}
map<int, int>map1;
map<int, int>map2;
class students {
protected:
	StudentRecord s;
	primarystudentIndex p;
	secondarystudentIndex1 s1;
	secondarystudentIndex2 s2;
	secondarystudentIndex3 s3;
	fstream fst, primarySTidx, secondarySTindx, secondarySTindx2, secondarySTindx3;
	
	vector<secondarystudentIndex3>vec;
	vector< primarystudentIndex >vec1;
	vector < secondarystudentIndex1>vec2;
	vector < secondarystudentIndex2>vec3;
	
public:
	students() {
		fst.open("students.txt", ios::out);
		primarySTidx.open("primarySTudentIndx.txt", ios::out);
		secondarySTindx.open("secondarySTudentIndxNAME.txt", ios::out);
		secondarySTindx2.open("secondarySTudentIndxGPA.txt", ios::out);
		secondarySTindx3.open("secondarySTudentIndxSDeptId.txt", ios::out);
	}

	void addst(int numofstudent)
	{
		for (int i = 0; i < numofstudent; i++) {
			map1.insert({ i ,fst.tellg() });
			cout << "enter student iD : ";
			cin >> s.StudentId;
			fst << s.StudentId << "|";
			cout << "enter student name : ";
			cin >> s.StudentName;
			fst << s.StudentName << "|";
			cout << "enter student level : ";
			cin >> s.SLevel;
			fst << s.SLevel << "|";
			cout << "enter Student GPA : ";
			cin >> s.SGPA;
			fst << s.SGPA << "|";
			cout << "enter student Dept ID : ";
			cin >> s.SDeptId;
			fst << s.SDeptId << "|" << endl;
		    p.offset = i;
			p.stId = s.StudentId;
			vec1.push_back(p);
			s1.stName = s.StudentName;
			s1.stId = s.StudentId;
			vec2.push_back(s1);
			s2.stGPA = s.SGPA;
			s2.stId = s.StudentId;
			vec3.push_back(s2);
			s3.SDeptId = s.SDeptId;
			s3.stId = s.StudentId;
			vec.push_back(s3);
			cout << "-----------------------------------------" << endl;
		}
sortStudentprimaryindx(vec1, primarySTidx);
		sortStudentsecondaryindx1(vec2, secondarySTindx);
		sortStudentsecondaryindx2(vec3, secondarySTindx2);
		sortStudentsecondaryindx3(vec, secondarySTindx3);
		fst.close();
		primarySTidx.close();
		secondarySTindx.close();
		secondarySTindx2.close();
		secondarySTindx3.close();
	}
void findstudentwithGPA(int numofstudent)
	{

		string line, temp, temp2, temp3, h;

		int r;
		char x, y, u, k;
		cout << "enter fist GPA : ";
		cin >> x;
		cout << "enter second GPA : ";
		cin >> y;

		ifstream myfile("secondarySTudentIndxGPA.txt");
		for (int i = 0; i < (numofstudent * 3); i++) {
			myfile >> u;
			if (u != ':') {
				temp.push_back(u);
			}
		}

		for (int i = 0; i < temp.length(); i++)
		{
			if (i % 2 == 0) {
				if (temp[i] >= x && temp[i] <= y) {
					temp2.push_back(temp[i + 1]);
				}
			}
			else
				continue;
		}
		ifstream myfile2("primarySTudentIndx.txt");
		for (int i = 0; i < (numofstudent * 3); i++) {

			myfile2 >> k;
			if (k != ':') {
				line.push_back(k);
			}

		}


		for (int i = 0; i < temp2.length(); i++) {
			temp3.push_back(binarySearch(line, 0, line.length(), temp2[i]));
		}

		ifstream myfile3("students.txt");
		for (int i = 0; i < temp3.length(); i++) {

			for (auto itr = map1.begin(); itr != map1.end(); ++itr) {
				if ((temp3[i] - '0') == itr->first) {
					myfile3.seekg(itr->second, ios::beg);
					getline(myfile3, h);
					cout << h << '\n';

				}

			}
		}

	}
};
//.......................................................................................
struct primaryDepartmentIndex {
			int DeptID, offset;

		};
bool my_cmp4(const primaryDepartmentIndex & a, const primaryDepartmentIndex & b)
		{

			return a.DeptID < b.DeptID;
		}
		void sortDepartmentprimaryindx(vector<primaryDepartmentIndex> vec, fstream & f) {
			sort(vec.begin(), vec.end(), my_cmp4);
			for (int i = 0; i < vec.size(); i++)
			{
				f << vec[i].DeptID << ":" << vec[i].offset << endl;
			}

		}
//........................................................................................
		struct secondaryDepartmentIndex1 {
			string DName;
			int DId;
		};
		bool my_cmp5(const secondaryDepartmentIndex1 & a, const secondaryDepartmentIndex1 & b)
		{

			return a.DName < b.DName;
		}
		void sortDepartmentsecondaryindx1(vector<secondaryDepartmentIndex1> vec, fstream & f) {
			sort(vec.begin(), vec.end(), my_cmp5);
			for (int i = 0; i < vec.size(); i++)
			{
				f << vec[i].DName << ":" << vec[i].DId << endl;
			}

		}
//.......................................................................................
struct secondaryDepartmentIndex2 {
			string HeadOfDepartment;
			int DId;
		};
		bool my_cmp6(const secondaryDepartmentIndex2 & a, const secondaryDepartmentIndex2 & b)
		{

			return a.HeadOfDepartment < b.HeadOfDepartment;
		}
		void sortDepartmentsecondaryindx2(vector<secondaryDepartmentIndex2> vec, fstream & f) {
			sort(vec.begin(), vec.end(), my_cmp6);
			for (int i = 0; i < vec.size(); i++)
			{
				f << vec[i].HeadOfDepartment << ":" << vec[i].DId << endl;
			}

		}
//.......................................................................................
		struct DepartmentRecord {
			int DeptID;
			string DeptName;
			string HeadOfDepartment;
};


class Department {
private:
	DepartmentRecord d;
	primaryDepartmentIndex Dp;
	secondaryDepartmentIndex1 Ds1;
	secondaryDepartmentIndex2 Ds2;
	
	fstream fdept, primaryDEPTidx, secondaryDEPTindx, secondaryDEPTindx2;
	vector<primaryDepartmentIndex>vec4;
	vector<secondaryDepartmentIndex1>vec5;
	vector< secondaryDepartmentIndex2>vec6;
public:
	Department() {
		fdept.open("Department.txt", ios::out);
		primaryDEPTidx.open("primaryDepartmentidx.txt", ios::out);
		secondaryDEPTindx.open("secondaryDepartmentindxNAME.txt", ios::out);
		secondaryDEPTindx2.open("secondaryDepartmentindxHEADOFDEPT.txt", ios::out);
}
	void addDept(int numofDepartment)
	{
		for (int i = 0; i < numofDepartment; i++) {
			map2.insert({ i,fdept.tellg() });
			cout << "enter Department iD : ";
			cin >>d.DeptID;
			fdept << d.DeptID<< "|";
			cout << "enter Department name : ";
			cin >> d.DeptName;
			fdept <<d.DeptName<< "|";
			cout << "enter Head Of Department : ";
			cin >> d.HeadOfDepartment;
			fdept << d.HeadOfDepartment << "|"<<endl;
			Dp.offset = i;
			Dp.DeptID = d.DeptID;
			vec4.push_back(Dp);
			Ds1.DId = d.DeptID;
			Ds1.DName = d.DeptName;
			vec5.push_back(Ds1);
			Ds2.DId = d.DeptID;
			Ds2.HeadOfDepartment = d.HeadOfDepartment;
			vec6.push_back(Ds2);
			cout << "-----------------------------------------" << endl;

		}

		sortDepartmentprimaryindx(vec4, primaryDEPTidx);
		sortDepartmentsecondaryindx1(vec5, secondaryDEPTindx);
		sortDepartmentsecondaryindx2(vec6, secondaryDEPTindx2);
		fdept.close();
		primaryDEPTidx.close();
		secondaryDEPTindx.close();
		secondaryDEPTindx2.close();
		

	}
};
//..................................................................................
struct primarySTAFFIndex {
	int StaffID, offset;

};
bool my_cmp7(const primarySTAFFIndex & a, const primarySTAFFIndex & b)
{

	return a.StaffID < b.StaffID;
}
void sortSTAFFprimaryindx(vector<primarySTAFFIndex> vec, fstream & f) {
	sort(vec.begin(), vec.end(), my_cmp7);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].StaffID<< ":" << vec[i].offset << endl;
	}

}
//.................................................................................
struct secondarySTAFFIndex1 {
	string Staffname;
	int stfId;
};
bool my_cmp8(const secondarySTAFFIndex1 & a, const secondarySTAFFIndex1 & b)
{

	return a.Staffname < b.Staffname;
}
void sortSTAFFsecondaryindx1(vector<secondarySTAFFIndex1> vec, fstream & f) {
	sort(vec.begin(), vec.end(), my_cmp8);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].Staffname << ":" << vec[i].stfId << endl;
	}

}
//.......................................................................................
struct secondarySTAFFIndex2 {
	string StaffDEgree;
	int stfId;
};
bool my_cmp9(const secondarySTAFFIndex2 & a, const secondarySTAFFIndex2 & b)
{

	return a.StaffDEgree < b.StaffDEgree;
}
void sortSTAFFsecondaryindx2(vector<secondarySTAFFIndex2> vec, fstream & f) {
	sort(vec.begin(), vec.end(), my_cmp9);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].StaffDEgree << ":" << vec[i].stfId << endl;
	}

}
//........................................................................................
struct secondarySTAFFIndex3 {
	string StaffDptID;
	int stfId;
};
bool my_cmp10(const secondarySTAFFIndex3 & a, const secondarySTAFFIndex3 & b)
{

	return a.StaffDptID < b.StaffDptID;
}
void sortSTAFFsecondaryindx3(vector<secondarySTAFFIndex3> vec, fstream & f) {
	sort(vec.begin(), vec.end(), my_cmp10);
	for (int i = 0; i < vec.size(); i++)
	{
		f << vec[i].StaffDptID << ":" << vec[i].stfId << endl;
	}

}
//.......................................................................................
struct Staffrecord {
	int StaffId;
	string StaffName;
	string SDegree;
	string	StaffDepartmentId;
};
class Staff {
private:
	Staffrecord sr;
	primarySTAFFIndex sfp;
	secondarySTAFFIndex1 sfs1;
	secondarySTAFFIndex2 sfs2;
	secondarySTAFFIndex3 sfs3;
	int lengthofS1file;
	int numofstaff;
	fstream fStaff, primarySTAFFidx, secondarySTAFFindx1, secondarySTAFFindx2, secondarySTAFFindx3;
	vector< primarySTAFFIndex>vec7;
	vector<secondarySTAFFIndex1>vec8;
	vector<secondarySTAFFIndex2>vec9;
	vector< secondarySTAFFIndex3>vec10;
public:
	Staff() {
		fStaff.open("Staff.txt", ios::out);
		primarySTAFFidx.open("primarySTAFFidx.txt", ios::out);
		secondarySTAFFindx1.open("secondarySTAFFindxSTAFFNAME.txt", ios::out);
		secondarySTAFFindx2.open("secondarySTAFFindxStaffDegree.txt", ios::out);
		secondarySTAFFindx3.open("secondarySTAFFindxStaffDEPTID.txt", ios::out);
	}                                 
	void addStaff()
	{
		cout << "enter num of Staff you want to add : ";
		cin >> numofstaff;
		for (int i = 0; i < numofstaff; i++) {
			cout << "enter Staff iD : ";
			cin >> sr.StaffId;
			fStaff << sr.StaffId<< "|";
			cout << "enter Staff name : ";
			cin >> sr.StaffName;
			fStaff <<sr.StaffName << "|";
			cout << "enter Staff degree : ";
			cin >> sr.SDegree;
			fStaff << sr.SDegree << "|";
			cout << "enter Staff Department Id : ";
			cin >> sr.StaffDepartmentId;
			fStaff << sr.StaffDepartmentId << "|" << endl;
			 
			sfp.offset = i;
			sfp.StaffID = sr.StaffId;
			vec7.push_back(sfp);
			sfs1.Staffname = sr.StaffName;
			sfs1.stfId = sr.StaffId;
			vec8.push_back(sfs1);
			sfs2.StaffDEgree = sr.SDegree;
			sfs2.stfId = sr.StaffId;
			vec9.push_back(sfs2);
			sfs3.StaffDptID = sr.StaffDepartmentId;
			sfs3.stfId = sr.StaffId;
			vec10.push_back(sfs3);
          
			cout << "-----------------------------------------" << endl;

		}
		sortSTAFFprimaryindx(vec7, primarySTAFFidx);
		sortSTAFFsecondaryindx1(vec8, secondarySTAFFindx1);
		sortSTAFFsecondaryindx2(vec9, secondarySTAFFindx2);
		sortSTAFFsecondaryindx3(vec10, secondarySTAFFindx3);
		lengthofS1file= secondarySTAFFindx1.tellg();
		fStaff.close();
		primarySTAFFidx.close();
		secondarySTAFFindx1.close();
		secondarySTAFFindx2.close();
		secondarySTAFFindx3.close();
	}
	void findStudentWithStaffName(int numofstudent) {
		map<string, char>stuffname_ID;
		int x;
		char z1,z2,z3,z4, cstufID , n2,STAFDEPTID,k2 ;
		string n,n1,dept_stafID,dsid, student_deptID1,StudentID3,line2, ofsetstudent,h2;
		cout << "Enter Staff Name : ";
		cin >> n;
		ifstream myfile4("secondarySTAFFindxSTAFFNAME.txt");

			for (int i = 0; i < (lengthofS1file- numofstaff); i++) {
			myfile4 >> z1;
			if (z1 != ':') {
				n1.push_back(z1);
			}
			else 
			{
				i++;
				myfile4 >> z2;
				n2 = z2;
				stuffname_ID.insert({ n1, n2 });
				n1 = "";
				n2 = ' ';
				i++;

			}
			
		}
			
			for (auto itr = stuffname_ID.begin(); itr != stuffname_ID.end(); ++itr) {
				if (itr->first == n) {
					cstufID = itr->second;
				}
			}
			ifstream myfile5("secondarySTAFFindxStaffDEPTID.txt");
			for (int i = 0; i < (numofstaff * 3); i++) {
				myfile5 >> z3;
				if (z3!= ':') {
					dept_stafID.push_back(z3);
				}
			}
			for (int i = 0; i < dept_stafID.length(); i++)
			{
				if (i % 2 != 0) {
					if (dept_stafID[i]== cstufID) {
						STAFDEPTID =dept_stafID[i - 1];
					}
				}
				else
					continue;
			}
		
			ifstream myfile6("secondarySTudentIndxSDeptId.txt");
			myfile6.seekg(0, ios::end);
			x=myfile6.tellg();
			myfile6.seekg(0, ios::beg);
			for (int i = 0; i < (x- numofstudent*2); i++) {
				myfile6 >> z4;
			
					if (z4 != ':') {
					student_deptID1.push_back(z4);
				}
			}
			
			
			for (int i = 0; i < student_deptID1.length(); i++)
			{
				if (i % 2 == 0) {
					if (student_deptID1[i]== STAFDEPTID) {
						StudentID3.push_back(student_deptID1[i+1]);
					}
				}
				else
					continue;
			}
		
			ifstream myfile7("primarySTudentIndx.txt");
			for (int i = 0; i < (numofstudent * 3); i++) {

				myfile7 >> k2;
				if (k2 != ':') {
					line2.push_back(k2);
				}

			}


			for (int i = 0; i < StudentID3.length(); i++) {
				ofsetstudent.push_back(binarySearch(line2, 0, line2.length(), StudentID3[i]));
			}
			

			ifstream myfile8("students.txt");
			for (int i = 0; i < ofsetstudent.length(); i++) {

				for (auto itr = map1.begin(); itr != map1.end(); ++itr) {
					if ((ofsetstudent[i] - '0') == itr->first) {
						myfile8.seekg(itr->second, ios::beg);
						getline(myfile8, h2);
						cout << h2 << '\n';

					}}}}


void  Departmentwithmaxnumberofstaff(int numofDepartment) {
	map <int, char>mp;
	char z6,maxx,k6;
	int c=1,c2=0;
	string staffIDdept,line3, ofsetdept,h5;
	ifstream myfile9("secondarySTAFFindxStaffDEPTID.txt");
	for (int i = 0; i < (numofstaff * 3); i++) {
		myfile9 >> z6;
		if (z6 != ':') {
			staffIDdept.push_back(z6);
							}
						
						}
						
	for (int i = 0; i < staffIDdept.length(); i++)
		{
		if (i % 2 == 0) {
		if (staffIDdept[i] == staffIDdept[i+2]) {
			c++;
		}
		else {
			mp.insert({ c,staffIDdept[i] });
			c = 1;
		}
		}
		else
			continue;
			}
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		if (itr->first > c2) {
			maxx = itr->second;
		}
	}

	ifstream myfile10("primaryDepartmentidx.txt");
	for (int i = 0; i < (numofDepartment * 3); i++) {

		myfile10 >> k6;
		if (k6 != ':') {
			line3.push_back(k6);
		}

	}

ofsetdept.push_back(binarySearch(line3, 0, line3.length(), maxx));
	
ifstream myfile11("Department.txt");
for(int i=0;i< ofsetdept.length();i++){
	for (auto itr = map2.begin(); itr != map2.end(); ++itr) {
		if ((ofsetdept[i] - '0') == itr->first) {
			myfile11.seekg(itr->second, ios::beg);
			getline(myfile11, h5);
			cout << h5 << '\n';

		}
	}
}

	


   }

};

int main()
{   
	
	int x,choose,y;
	Department d;
	cout << "enter num of Departments you want to add : ";
	cin >> y;
	d.addDept(y);
	Staff st;
	st.addStaff();
    students s;
	cout << "enter num of student you want to add : ";
	cin >> x;
    s.addst(x);
	
	while (true) {
		cout<<"1-Find the Students with GPA between X and Y \n2-Find the students joined a department managed by a Staff member with Name = “StaffName” \n3-Find the Department with max number of staff members.\n4-exite"<<endl ;
		cout << "choose what u want : ";
		cin >>choose;
		if (choose == 1) {
			s.findstudentwithGPA(x);
		}
		if (choose == 2) {
			st.findStudentWithStaffName(x);
	 }
		if (choose == 3) {
			st.Departmentwithmaxnumberofstaff(y);
		}
		if (choose == 4) {
			break;
		}

	}
	
	
	return 0;
}

