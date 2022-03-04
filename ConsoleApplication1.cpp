#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
#define MAX 300

int myStrlen(char p[], int k)
{
	int n = 0;
	while (*(p + n) != '\0') n++;
	return n - k;
}

void myMemmove(char p[], int vt, int k)
{
	int n = myStrlen(p, 0);
	for (int i = vt + k; i < n; ++i) {
		*(p + i - k) = *(p + i);
	}
	for (int i = n - k; i < n; ++i) {
		*(p + i) = '\0';
	}
}

void Normalize(char p[])
{
	while (*p == ' ') {
		myMemmove(p, 0, 1);
	}
	while (*(p + myStrlen(p, 0) - 1) == ' ') {
		myMemmove(p, myStrlen(p, 0) - 1, 1);
	}
	int n = myStrlen(p, 0);
	for (int i = 1; i < n; ++i) {
		if (*(p + i) == ' ' && *(p + i - 1) == ' ') {
			myMemmove(p, i, 1);
			n--;
			i--;
		}
	}
	/*for (int i = 0; *(p + i) != '\0'; i++)
		if ((*(p+i) >= 'A') && (*(p+i) <= 'Z')) *(p+i) = tolower(*(p+i));
	*p = toupper(*p);
	for (int i = 1; *(p+i) != '\0'; i++)
		if (*(p+i - 1) == ' ') *(p+i) = toupper(*(p+i));*/
}

void NoiString(char p[], char h[])
{
	Normalize(p);
	Normalize(h);
	char* y = new char[MAX];
	int n = myStrlen(p, 0)+1;
	int m = myStrlen(h, 0);
	int k = n + m;
	for (int i = 0; i < myStrlen(p, 0); i++)
		y[i] = p[i];
	y[n-1] = ' ';
	int j = 0;
	for (int i = n; i <= k; i++)
	{
		y[i] = h[j];
		j++;
	}
	Normalize(y);
	cout << y;
}

int main()
{
	char* p = new char[MAX];
	char* h = new char[MAX];
	cin.getline(p, MAX);
	cin.getline(h, MAX);
	NoiString(p, h);
	return 0;
}