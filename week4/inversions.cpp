#include <iostream>
#include <vector>

using namespace std;

long long binary_search(const vector<long long> &a, long long x) {
  long long left = 0, right = (long long)a.size()-1;
  while(left<=right){

    long long mid =left+(right-left)/2;
//    if(a[mid]==x) {
//     return mid;
//    }
    if(a[mid]>x){
    right = mid-1;

    }
    else{
    left = mid+1;
    }

  }
//if(right<0) right= 0;
if(right!= -1 && a[right]==x)
right--;
return right+1;
  //write your code here
}
long long inversions = 0;
void Merge(vector<long long>&a, long long left,long long mid, long long right)
{

    long long n1 = mid-left+1;
    long long n2 = right-mid;
    long long inv1 = 0;
    long long inv2 = 0;

    vector<long long> arr_l(n1);
    vector<long long> arr_r(n2);

    for(long long i=0;i<n1;i++)
    {
    arr_l[i] = a[left+i];

    }

    for(long long j=0;j<n2;j++)
    {
    arr_r[j] = a[mid+1+j];

    }
    for(long long i=0;i<n1;i++)
    {
//    cout<<arr_r[i]<<" "<<binary_search(arr_l,arr_r[i])<<"\n";
    inversions+=binary_search(arr_r,arr_l[i]);
//    cout<<left<<" "<<right<<" "<<i<<" "<<arr_l[i]<<" "<<binary_search(arr_r,arr_l[i])<<"\n";
    }

    long long i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
    if(arr_l[i]<=arr_r[j])
    {
    a[k] = arr_l[i];
    i++;
    }
    else{
    inv1++;
//    cout<<arr_l[i]<<" ";
    a[k]=arr_r[j];
    j++;
    }

    k++;

    }

   while(i<n1){
   a[k] = arr_l[i];
   i++;
   k++;
   inv2++;

   }

     while(j<n2){
   a[k] = arr_r[j];
   j++;
   k++;


   }


//   inversions+=(inv1*inv2);
//    cout<<left<<" "<<right<<" "<<inversions<<"\n";

    }



void MergeSort(vector<long long>&a, long long left, long long right)
{
    if(right<=left)   return;

    long long mid= left+(right-left)/2;

    MergeSort(a,left,mid);
    MergeSort(a,mid+1,right);

    Merge(a,left,mid,right);




}

int main() {
  int n;
  std::cin >> n;
  vector<long long > a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<long long > b(a.size());

  MergeSort(a, 0, a.size()-1);
//  for (size_t i = 0; i < a.size(); i++) {
//    std::cout << a[i]<<" ";
//  }

  std::cout << inversions << '\n';
}
