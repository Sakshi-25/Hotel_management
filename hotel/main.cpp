#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;
// ASSUME THERE  ARE HOTEL ROOMS AS PER USER’S REQUIREMENT i.e HOTEL ROOMS ARE ALWAYS AVAILABLE.

struct Hotel_book                                 // Structure of Hotel
    {    int Room_no;
         struct Hotel_book *next;
    }*first=NULL,*last=NULL;                    // global variable pointing start and end of list

typedef struct Hotel_book* Bptr;

Bptr create()                                 // node created and returns its own address
{       Bptr temp;

        cout<< "\n Booking a new Room!";
        temp=new Hotel_book;
        cout<<"\n Enter the room no. of hotel :-  ";
        cin>>temp->Room_no;
        temp->next=NULL;
        cout<<"\n Room number ”<<temp->Room_no<<”Booked!!";
        return temp;

}


Bptr insert_frnt()                    //  Book Room at starting of list
{       Bptr A=create();

        if(first==NULL)
            last=first=A;
        else
            {   A->next=first;
                first=A;
            }

        cout<<"\n  Room inserted at the starting of list!!";
        return first;

}

Bptr insert_end()                   // insertion of node at the end of list
{
        Bptr B=create();

        if(last==NULL)
            last=first=B;
        else
            {   last->next= B;
                last=B;
            }

        cout<<"\n Room inserted at the end of list!!";
        return first;
}

Bptr insert_pos(int pos)                    // insert at position :- if pos=3, element at 3 moves to 4 & new element added at 3.
{
    Bptr C=create();
    Bptr point=first;

    for(int i=1;i<pos-1;i++)
        point=point->next;

        C->next=point->next;
        point->next=C;

    cout<<"\n Room Inserted at position "<<pos;
    return first;
}

void Display(Bptr abc)                                  // DISPLAY the linked list
{
    int count=0;
        cout<<"\n";
    while(abc!=NULL)
    {   cout<<"\n"<<"Booking number:  "<<count+1<<" \tRoom number: "<<abc->Room_no;
        abc=abc->next;
        count++;
    }
}


int trav_rec()                                  // COUNT the number of elements in the list.
{   Bptr w=first; int count=0;
    while(w)
    {       count++;    w=w->next;
    }
        return count;
}



void del_pos(int which)                                 //  Check out from a room
{
    Bptr delptr=first,opt=first->next;

    if (which==1)
    {      first=first->next;      free(delptr);   }
    else
        {   for(int i=2;i<which;i++)
            {
                opt=opt->next;
                delptr=delptr->next;
            }
            delptr->next=opt->next;
            free(opt);
        }
        cout<<"\n CHECK OUT from Booking number "<<which <<"\n";
}

int main()
{
    int choice , place ,t;
    do
    {
        cout<<"\n Enter operations to be done on your list of Rooms of hotel:- \n #~ ADD new Room in START = 1 \n #~ADD new Room at END = 2 \n #~ ADD new Room at any position in list =3 \n #~ DISPLAY the list Rooms booked = 4 \n #~ Check out from Rooms in list =5 \n TYPE-  ";
        cin>>choice;

        switch  (choice)
        {
            case 1 : first=insert_frnt();     break;
            case 2 : first=insert_end();      break;
            case 3 :     cout<<" \n Enter the Booking no.at which new room is to be inserted  = ";
                          cin>>place;
                                insert_pos(place);
                         break;
            case 4 : Display(first); break;
            case 5 : cout<< " \n Enter Booking no. to check out =";     cin>>place;
                        del_pos(place);     break;
            default : cout<<" \n wrong Choice!! BYE!!"; exit(0);
        }

                cout<<"\n \n EXIT -> 0   \t   AGAIN -> Any Key  \n ";
                cin>>t;
    }while(t);

    return 1;
}
