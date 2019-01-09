#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string add(string a,string b)
{
	string result;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	unsigned int const ll = min(a.length(),b.length());
	unsigned int carry = 0,ad,bd,r;
	for(unsigned int i = 0; i < ll;i++)
	{
		ad = a[i] - '0';
		bd = b[i] - '0';
		r = ad + bd + carry;
		carry = r/10;
		result += '0'+r%10;
	}
	for(unsigned int i = ll; i < a.length();i++)
	{
		ad = a[i] - '0';
		r = ad + carry;
		carry = r/10;
		result += '0' + r%10;
	}
	for(unsigned int i = ll; i < b.length();i++)
	{
		bd = b[i] - '0';
		r = bd + carry;
		carry = r/10;
		result += '0' + r%10;
	}
	if(carry)
		result += to_string(1);
	reverse(result.begin(),result.end());
	return result;
}

int main()
{
	string a,b;
	a = "999",b="9";
	string result = add(a,b);
	int sw = result.length();
	cout << setw(sw) << a << " +\n" << setw(sw) << b << "\n"
	<< setw(sw) << setfill('-') << "" << "\n" << add(a,b);
}
