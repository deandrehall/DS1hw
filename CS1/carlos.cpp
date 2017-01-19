#include<iostream>
#include<cstdlib>
using namespace std;
       
class product {
      public:
      int weight;
      //int acmeprods[100];
      double price;
      double totprice(product& pr){
             double total;
             total=pr.weight*pr.price;
             return total; } 
             };
       
int main(){
  /*   product celery;
   celery.price=2.99;
     celery.weight=2;
   // cout<<"total price is "<<totprice(celery.weight,celery.price)<<endl;
   cout<<"total price is "<<totprice(celery)<<endl; */
   product celery[100];
   celery[0].price=1.99;
   celery[0].weight=2;
    celery[1].price=1.99;
   celery[1].weight=2;
   for(int i=0;i<2;i++){
           cout<<"Product "<< i+1<< ":"<<endl;
           cout<<"price "<<celery[i].price<<endl;
           cout<<"weight "<<celery[i].weight<<endl;
          // cout<<"price "<<product.price(acmeprods[i])<<endl;
          // cout<<"weight "<<acmeprods[i].weight<<endl;
           //cout<<"total cost "<<totprice(acmeprods[i])<<endl<<endl;
           cout<<"total cost "<<celery[i].totprice(celery[i])<<endl<<endl;
           }
           
    system("pause");
    return 0;
}
