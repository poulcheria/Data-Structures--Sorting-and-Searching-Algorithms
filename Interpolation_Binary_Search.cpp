#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

//INTERPOLATIONSEARCH
int interpolationSearch(int arr[], int lo,
                        int hi, int x)
{
    int pos;

    if ( lo <= hi && x >= arr[lo] &&
                     x <= arr[hi])
    {
        pos = lo + (((double)( hi - lo ) /
                         (arr[hi] - arr[lo])) *
                               (x - arr[lo]));

        if( arr[pos] == x )
            return pos;

        if( arr[pos] < x )
            return interpolationSearch(arr, pos + 1, hi, x);

        if( arr[pos] > x )
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

//BINARYSEARCH
int binarySearch(int intlist[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (intlist[mid] == x)
            return mid;


        if (intlist[mid] > x)
            return binarySearch(intlist, l, mid - 1, x);

        return binarySearch(intlist, mid + 1, r, x);
    }


    return -1;
}

int main(){
string searchstringtemp, strline, searchtime, humstring[8222], tempstring[8222];
int i, inp, inp1, itsat, searchint,  humint[8222], tempint[8222];
ifstream inhumstring ("finalstringhum.txt");
ifstream inhumint("finalinthum.txt");
ifstream intempstring ("finalstringtemp.txt");
ifstream intempint("finalinttemp.txt");

//load sorted files to lists
if(inhumstring.is_open()){
        i=0;
    while(getline(inhumstring, strline))
    {
        humstring[i]=strline;

    i++;
    }
}
inhumstring.close();

if(intempstring.is_open()){
        i=0;
    while(getline(intempstring, strline))
    {
        tempstring[i]=strline;

    i++;
    }
}
intempstring.close();

if(inhumint.is_open()){
        i=0;
    while(getline(inhumint, strline))
    {
       humint[i]=stoi(strline);

    i++;
    }
}
inhumint.close();

if(intempint.is_open()){
        i=0;
    while(getline(intempint, strline))
    {
        tempint[i]=stoi(strline);

    i++;
    }
}
intempint.close();


//do
cout<<"Enter 0 for Binary Search, 1 for Interpolation Search..."<<endl;
cin>>inp1;

cout<<"Enter 0 to search for humidity, 1 to search for temperature..."<<endl;
cin>>inp;

cout<<"Enter date/time to search for in form MM/DD/hh/mm..."<<endl;
cin>>searchtime;


searchstringtemp+=(searchtime.at(1));
searchstringtemp+=(searchtime.at(3));
searchstringtemp+=(searchtime.at(4));
searchstringtemp+=(searchtime.at(6));
searchstringtemp+=(searchtime.at(7));
searchstringtemp+=(searchtime.at(9));
searchstringtemp+=(searchtime.at(10));
searchint=stoi(searchstringtemp);

if (inp1==0){
    if (inp==0){
            itsat=binarySearch(humint, 0, 8221, searchint);

            if (itsat==-1) cout<<"not in list"<<endl;
            else cout<<humstring[itsat]<<endl;
            }
    else{
            itsat=binarySearch(tempint, 0, 8221, searchint);
            if (itsat==-1) cout<<"not in list"<<endl;
            else cout<<tempstring[itsat]<<endl;
            }
}
else {
    if (inp==0){
            itsat=interpolationSearch(humint, 0, 8221, searchint); //paremvolh();

            if (itsat==-1) cout<<"not in list"<<endl;
            else cout<<humstring[itsat]<<endl;
            }
    else{
            itsat=interpolationSearch(tempint, 0, 8221, searchint); //paremvolh();
            if (itsat==-1) cout<<"not in list"<<endl;
            else cout<<tempstring[itsat]<<endl;
            }
}

return 0;
}
