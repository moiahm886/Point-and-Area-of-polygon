#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
float areaofpoly(vector<pair<int, int>>vect)
{
	float x = 0, y = 0;
	vect.push_back(make_pair(vect[0].first, vect[0].second));
	for (int i = 0; i < vect.size() - 1; i++)
	{
		x += vect[i].first * vect[i + 1].second;
		y += vect[i].second * vect[i + 1].first;
	}
	return (abs(x - y) / 2);
}
bool inpolygon(vector<pair<int, int>>vect, pair<int, int>p)
{
	int area = 0;
	for (int i = 0; i < vect.size() - 1; i++)
	{
		vector<pair<int, int>>v;
		v.push_back(p);
		v.push_back(make_pair(vect[i].first, vect[i].second));
		v.push_back(make_pair(vect[i + 1].first, vect[i + 1].second));
		area += areaofpoly(v);
	}
	vector<pair<int, int>>v;
	v.push_back(p);
	v.push_back(make_pair(vect[0].first, vect[0].second));
	v.push_back(make_pair(vect[vect.size() - 1].first, vect[vect.size() - 1].second));
	area += areaofpoly(v);
	return area == areaofpoly(vect) ? true : false;

}
int main()
{
	vector<pair<int, int>>vect;
	int numbers;
	cin >> numbers;
	for (int i = 0; i < numbers; i++)
	{
		int x, y;
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}
	pair<int, int>p;
	cout << "press 1 for area and press 2 if you want to know if the coordinates lies in a polygon or not\n";
	char ch;
	cin >> ch;
	if (ch == '2')
	{
		cout << "enter coordintes\n";
		int x, y;
		cin >> x >> y;
		p.first = x;
		p.second = y;
		if (inpolygon(vect, p))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "it does not lie in polygon\n";
		}
	}
	else if (ch == '1')
	{
		cout << "the area of polygon is " << areaofpoly(vect) << endl;
	}

}