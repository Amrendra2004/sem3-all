#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;

int tNum = 2;
int sumArray[5] = {0};
int arr[15] = {10, 10, 10, 10, 10, 12, 10, 10, 10, 10, 10, 10, 12};
int tSize = ceil(15/tNum), tPart = 0;
void *sum (void* arg){

   int part = tPart;
   tPart++;
   for (int i = part*tSize ; i < (part+1)*tSize ; i++) {
      sumArray[part] += arr[i];
   }
   pthread_exit (NULL);
}

int main(){
   pthread_t threadID[tNum];
   
   for (int i = 0 ; i < tNum ; i++) {
      pthread_create (&threadID[i], NULL, sum, (void*)NULL);
   }
   
   for (int i = 0 ; i < tNum ; i++) {
      pthread_join (threadID[i], NULL);
   }
   
   int sum = 0;
   for (int i = 0 ; i < tNum ; i++) {
      sum += sumArray[i];
   }
   cout << "Sum of array = " << sum<<endl;
   return 0;
}