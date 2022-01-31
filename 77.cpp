#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
string szyfruj(string s, string klucz) 
{
  	string rez;
  	int klucz_index=0;
  	int m;
  	int index;
  	int wszys=0;
  	for (int i=0; i<s.length(); i++) 
		{
    		if (s[i]<'A' || s[i]>'Z') 
			{
      			rez += s[i];
      			continue;
    		}
    		m=(int) klucz[klucz_index]-65;
    		index=(int) s[i]-65;
    		index += m;
    		if (index>25) index=(index-1)%25;
    		index += 65;
    		rez += (char) index;
    		klucz_index++;
    		if(klucz_index==klucz.length()) klucz_index=0;
  		}
  	return rez;
}
void zadanie1() 
{
  	ifstream in("dokad.txt");
  	string s="";
  	string t;
  	while (in>>t) s+=t +" ";
  	string klucz="LUBIMYCZYTAC";
  	cout<<"A:"<<19<<endl;
  	cout<<"B:"<<szyfruj(s, klucz)<<endl<<endl;
}
void zadanie2() 
{
  	string klucz="ZLODZIEJCZASU"; 
  	string s="";
  	string t;
  	ifstream in("szyfr.txt");
  	while (in>>t) s += t+" ";
  	int klucz_index=0;
  	for (int i=0; i<s.length(); i++) 
	  	{
    		if (s[i]==' ' || s[i]==',' || s[i]=='.') continue;
    		s[i] -= klucz[klucz_index];
    		s[i] +=65;
    		if (s[i]<'A') s[i]+=26;
    		klucz_index++;
    		if (klucz_index==klucz.length()) klucz_index=0;
  		}
  	cout<<s<<endl<<endl;
}
int main() 
{
  	zadanie1();
  	zadanie2();
};
