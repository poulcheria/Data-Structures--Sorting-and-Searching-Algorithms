#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>



using namespace std;

//COUNTSORT
void countSort(vector<int> &humlist,vector<string> &strhumlist)
{
    int output[humlist.size()];
    string stroutput[strhumlist.size()];

    vector <int> counter;
    int i;

    for (i=0;i<=4990000;i++) counter.push_back(0);


    for (i = 0; humlist[i]; ++i)
        ++counter[humlist[i]];

    for (i = 1; i <= 3952351; ++i)
        counter[i] += counter[i - 1];

    // Build the output character array
    for (i = 0; humlist[i]; ++i) {

        output[counter[humlist[i]] - 1] = humlist[i];
        stroutput[counter[humlist[i]] - 1] = strhumlist[i];
        --counter[humlist[i]];
    }


    for (i = 0; humlist[i]; ++i){
        humlist[i] = output[i];
        strhumlist[i] = stroutput[i];
    }
}


//HEAPSORT
void heapify(vector<int> &humlist,vector<string> &strhumlist, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && humlist[l] > humlist[largest])
        largest = l;

    if (r < n && humlist[r] > humlist[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(humlist[i], humlist[largest]);
         swap(strhumlist[i], strhumlist[largest]);
        // Recursively heapify the affected sub-tree
        heapify(humlist,strhumlist, n, largest);
    }
}


void heapSort(vector<int> &humlist,vector<string> &strhumlist, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(humlist,strhumlist, n, i);


    for (int i = n - 1; i >= 0; i--) {

        swap(humlist[0], humlist[i]);
        swap(strhumlist[0], strhumlist[i]);

        heapify(humlist,strhumlist, i, 0);
    }
}

int main() {
string line, newline, temptimestring, temptempstring, tempsubstring;
char check;
int i, temptimeint;
vector<string> stringlist, templist;
vector<int> timelist;
ifstream intempfile ("hum.txt");
ofstream outnewtempfile ("newhum.txt");
ofstream finaloutputhumstring("finalstringhum.txt");
ofstream finaloutputhumint("finalinthum.txt");

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


ifstream innewtempfile ("newhum.txt");

while (getline(innewtempfile, newline, ',')) {
        check=newline.at(0);
if (check==' ')  newline=newline.substr(1, newline.size()-1);

    stringlist.push_back(newline);

    //cout<<newline<<'\n';

}
//cout<<stringlist.size(); //8222
while (i < stringlist.size()) {

        temptimestring.push_back(stringlist[i].at(6));
        temptimestring.push_back(stringlist[i].at(7));
        temptimestring.push_back(stringlist[i].at(9));
        temptimestring.push_back(stringlist[i].at(10));
        temptimestring.push_back(stringlist[i].at(12));
        temptimestring.push_back(stringlist[i].at(13));
        temptimestring.push_back(stringlist[i].at(15));
        temptimestring.push_back(stringlist[i].at(16));

        //temptempstring=stringlist[i].substr(23);

    //cout<<temptempstring.size()<<'\n';
    temptimeint=stoi(temptimestring);

    templist.push_back(temptempstring);
    timelist.push_back(temptimeint);

    temptimestring.clear();
    temptempstring.clear();

      i++;
   }

    int n = timelist.size();
    int inp;
    cout<<"Enter 0 for HeapSort, 1 for CountSort..."<<endl;
    cin>>inp;
    if(inp==0){
    heapSort(timelist,stringlist,n);
    }
    else{
    countSort(timelist,stringlist);
    }

    i=0;
   while (i < stringlist.size()) {

   //cout << timelist[i] << endl;
    cout<<stringlist[i]<<endl;
    finaloutputhumint<<timelist[i]<<endl;
    finaloutputhumstring<<stringlist[i]<<endl;
    //cout<<templist[i]<<'\n';

    i++;

   }
finaloutputhumint.close();
finaloutputhumstring.close();
   //times are indexed in the vector timelist, program works for hum.txt too                      



return 0;
}
