#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;




//QUICKSORT
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}



int partition (vector<int>&temp,vector<string> &sttemp, int low, int high)
{
    int pivot = temp[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (temp[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&temp[i], &temp[j]);

           string tempor;
           tempor=sttemp[i];
           sttemp[i]=sttemp[j];
           sttemp[j]=tempor;
        }
    }
    swap(&temp[i + 1], &temp[high]);

       string tempor2;
        tempor2=sttemp[i+1];
        sttemp[i+1]=sttemp[high];

          sttemp[high]=tempor2;

    return (i + 1);
}


void quickSort(vector<int>&temp,vector<string> &sttemp, int low, int high)
{
    if (low < high)
    {

        int pi = partition(temp,sttemp, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(temp,sttemp, low, pi - 1);
        quickSort(temp,sttemp, pi + 1, high);
    }
}






//MERGESORT

void merge(vector<int> &temp,vector<string> &sttemp, int l,int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1],R[n2];
    string L2[n1],R2[n2];

     for (i = 0; i < n1; i++){
        L[i] = temp[l + i];
        L2[i] =sttemp[l+i];

     }

    for (j = 0; j < n2; j++){
        R[j] = temp[m + 1 + j];
        R2[j] = sttemp[m + 1 + j];
    }

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {

            temp[k] = L[i];
            sttemp[k]=L2[i];
            i++;
        }
        else {
            temp[k] = R[j];
            sttemp[k]=R2[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
   while (i < n1) {
        temp[k] = L[i];
        sttemp[k]=L2[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        temp[k] = R[j];
        sttemp[k]=R2[j];
        j++;
        k++;
    }


}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */

void mergeSort(vector<int> &temp,vector<string> &sttemp, int l, int r)
{
    if (l < r) {


        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(temp,sttemp, l, m);
        mergeSort(temp,sttemp, m + 1, r);

        merge(temp,sttemp, l, m, r);
    }
    if(1)
    {
      int p=0;
         while (p < temp.size()) {


    p++;

   }

    }
}


int main() {
string line, newline, temptimestring, temptempstring, tempsubstring;
char check;
int i, temptimeint;
vector<string> stringlist, templist;
vector<int> timelist;
ifstream intempfile ("tempm.txt");
ofstream outnewtempfile ("newtempm.txt");
ofstream finaloutputtempstring("finalstringtemp.txt");
ofstream finaloutputtempint("finalinttemp.txt");
if(intempfile.is_open())
{
    while (getline (intempfile, line)){
        line += ',';

 line.erase(remove(line.begin(), line.end(), '{'), line.end());
 line.erase(remove(line.begin(), line.end(), '}'), line.end());

 outnewtempfile<<line;

}
    intempfile.close();
    outnewtempfile.close();
}
    else cout<<"file no open ";


ifstream innewtempfile ("newtempm.txt");

while (getline(innewtempfile, newline, ',')) {
        check=newline.at(0);
if (check==' ')  newline=newline.substr(1, newline.size()-1);

    stringlist.push_back(newline);

}

while (i < stringlist.size()) {

        temptimestring.push_back(stringlist[i].at(6));
        temptimestring.push_back(stringlist[i].at(7));
        temptimestring.push_back(stringlist[i].at(9));
        temptimestring.push_back(stringlist[i].at(10));
        temptimestring.push_back(stringlist[i].at(12));
        temptimestring.push_back(stringlist[i].at(13));
        temptimestring.push_back(stringlist[i].at(15));
        temptimestring.push_back(stringlist[i].at(16));


    //cout<<temptempstring.size()<<'\n';
    temptimeint=stoi(temptimestring);

    templist.push_back(temptempstring);
    timelist.push_back(temptimeint);

    temptimestring.clear();
    temptempstring.clear();

      i++;
   }

    i=0;


int input;
cout<<"Enter 0 for Merge, 1 for Quick"<<endl;
cin >> input  ;
if (input==0) {

   //times are indexed in the vector timelist, program works for hum.txt too                             ////while tempteratures in the vector templist as strings(for...reasons...)!
  mergeSort(timelist,stringlist,0,timelist.size()-1);
  while (i < timelist.size()) {

  //cout << timelist[i] << endl;
    cout<<stringlist[i] <<endl;

    i++;
  }
}
else {
  quickSort(timelist,stringlist,0,timelist.size()-1);

   while (i < timelist.size()) {

    //cout << timelist[i] << endl;
    cout<<stringlist[i] <<endl;




    i++;

   }
}
    i=0;
   while (i < stringlist.size()) {

   //cout << timelist[i] << endl;
    //cout<<stringlist[i]<<endl;
    finaloutputtempint<<timelist[i]<<endl;
    finaloutputtempstring<<stringlist[i]<<endl;
    //cout<<templist[i]<<'\n';

    i++;

   }
finaloutputtempint.close();
finaloutputtempstring.close();
return 0;
}























