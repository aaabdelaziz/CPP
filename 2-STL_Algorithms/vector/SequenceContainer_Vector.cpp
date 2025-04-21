#include <iostream>
#include <vector>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{

	/* -------- EX1 ------------ */

    //   https://www.youtube.com/watch?v=ltBdTiRgSaw&index=2&list=PL5jc9xFGsL8G3y3ywuFSvOuNm3GjBwdkb
    vector<int> vec;  //is a dynamic array created in Heap  ---> note that vector is a container, with contiguous locations allocated in Heap

    vec.push_back(4);  //push to end of array after last element O(1)
    vec.push_back(1);
    vec.push_back(8);  //So, vec will be vec={4,1,8}

    //vect has an iterator   ----> Here is the iterator that itrate over the container
    vector<int>::iterator itr1= vec.begin();
    vector<int>::iterator itr2=vec.end();

    for(vector<int>::iterator itrat=itr1 ; itrat!=itr2 ; ++itrat)
        cout<<*itrat<<" " <<endl;

    //note that the vector is half-open :   [begin:end)
    //this means that the end pointer is pointing to next location after last element in vector ,

    sort(itr1,itr2);   //sorting algorithm will slow the speed due to locality of reference   ----> Here the Algorithm use the iterator to go through the container
    //The Algoritm only work with the iterator

    //after Sorting
    cout<<"After Sorting"<<endl;

    for(vector<int>::iterator itrat=itr1 ; itrat!=itr2 ; ++itrat)
        cout<<*itrat<<" " <<endl;

    
    /******************* traverse **********************/
    //Or I can traverse the vector as:
    vector<int>::iterator it=vec.begin();
    for(auto it: vec)     //  --> in C++11   , auto will give automatically the type required to it
        cout<<it<<" "<<endl;

     //Also, you can view first element only as
     cout<< *vec.begin()<<endl;
     cout<< "vector size "<< vec.size()<<endl;

     //But can`t view the last element, as it`s half open
     //cout<<*vect.end()<<endl;  (X) wrong

     //We can Also access the vector as an array
     cout<<vec[0]<<" - "<<vec[1]<<" - "<<vec[2]<<endl;
     cout<<"Or I can access it as "<<endl;
     cout<<vec.at(0)<<" - "<<vec.at(1)<<" - "<<vec.at(2)<<endl;

     //we can also traveres it as an array
     for (int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" * ";
     }
     cout << endl;

     //We can use the pointer to point to a vector and access it
     int *ptr=&vec[0];
     ptr[2]=6;
     for (int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" * ";
     }

     //member functions of vector container class
     if(vec.empty()) cout<< "can`t access vect"<<endl;
     cout<<vec.size();   //size of vec , or num of its elements
     vector<int> vec2(vec);   //here we use copy constructor to copy to vec2: {1,4,6}
     vec.clear(); //vec becomes empty, remove all elements in container
     vec2.swap(vec);  // now vec2 becomes empty and vec will has the 3 numbers

     //STl is an efficient and optimized , so we prefer to use its


 	/* -------- EX2 ------------ */
    //you can also initialize the vector as
    vector<int> veec={1,4,3,10,22};

    //you can use a pointer to point to the first element in the vector as
    int *pp=veec.data();    //data() get the address of first element of vector
    cout<<endl<<"======"<<endl;
    for (int i=0 ; i<veec.size();i++)
    cout<<*pp++<<endl;

 	/* -------- EX3 ------------ */

    //declaring vector of pairs
     vector< pair<int,int> > vect;

     // initialising 1st and 2nd element of
     // pairs with array values
     int arr[] = {10, 20, 5, 40 };
     int arr1[] = {30, 60, 20, 50};


     //Get Number of elements
     int n = sizeof(arr)/sizeof(arr[0]);

     // Entering values in vector of pairs
     for (int i=0; i<n; i++)
         vect.push_back( make_pair(arr[i],arr1[i]) );

     // Printing the vector
     for (int i=0; i<n; i++)
     {
         // "first" and "second" are used to access
         // 1st and 2nd element of pair respectively
         cout << vect[i].first << " "
              << vect[i].second << endl;
     }

  	/* -------- EX4 s------------ */

     class Move{};
     class Piece{};

     Move ob;
     Piece dd;
    //To make pair of pointers to classes
    vector <pair <Move*, Piece*> > moveList;

    //There's not enough code to say for sure, but a wild guess is you created the objects on the stack and the stack frame they lived in is no longer alive.
   // In this case one fix is to allocate the objects from the heap, like so:
   Move * move = new Move;
   Piece * piece = new Piece;

   moveList.push_back( make_pair(move, piece) );
   moveList.push_back( make_pair(&ob, &dd) );





   //A possible idiomatic solution that addresses memory management and exception safety can be achieved by using smart pointers:

//   typedef pair< shared_ptr<Move>, shared_ptr<Piece> > MovePiece;
//   vector< MovePiece > moveList;
//   moveList.push_back( MovePiece(make_shared<Move>(), make_shared<Piece>()) );

    return 0;
}

/*
Notes about vector:
- Vector insert using vector.push_back(val) is fast as it's O(1)
- Vector insert using vector.push_back(val) is fast as it's O(1)

*/