#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include<vector>
#include<fstream>
#include<stack>

class playlist {
    
    public:
        string sgname;
        
        
    public:
        playlist*prev;
        playlist* next;
        playlist*saveprev;
        playlist*savenext;
        
    public:
     // constructor
    playlist (string sgname){    
        this-> sgname= sgname;
        this-> prev=NULL;
        this-> next= NULL; 
        this->saveprev=NULL;
        this->savenext=NULL;
    }  

    //destructor
    ~playlist(){

}    

};

// separate class for multiple playlists
class playlistmanager {

    public:
    playlist*head= NULL;
    playlist*tail= NULL;
     
     // constructor
    playlistmanager (){    
       
        this-> head=NULL;
        this-> tail= NULL; 
    }
   
public:
    playlist* prev;
    playlist* next;

public:
    //adding a song to the playlist
void addsong (string sgname ){

    playlist*temp = new playlist (sgname);
    
    if (tail== NULL){
        tail = temp;
        head= temp;
    }
    else {
        tail->next=temp;
        temp-> prev= tail;
        tail = temp;
    }
    
}

void printplaylist (){

    playlist*temp= head;
    while (temp!=NULL){
        cout<< temp->sgname<<endl;
        temp=temp->next;
    }    
}

// destructor
~playlistmanager(){

}    


void deletesong ( int position){

   //invalid position
   int len = lengthofplaylist();
    if(position> len){
        cout<<"invalid position"<<endl;
    }

    //song  is at head poition
    if(position==1){
        playlist* temp= head;
        temp->next-> prev =NULL;
        head = temp-> next;
        temp-> next= NULL;
        delete temp; 
    }
   
    else{

        playlist* current= head;
        playlist* prev = NULL;
        
        //traversing
        int count=1;
        while (count<position){
            prev= current;
            current= current->next;
            count++;
        }

        current-> prev=NULL;
        prev-> next= current -> next;
        current-> next= NULL;
        delete current;    
    }

}

bool search (int arr [], int size, int key){
    for (int j=0; j<size; j++){
        if (arr[j]==key){
            return true;
        }
    }
    return false;
}

void shuffle(){
    playlist *temp = head;
    int len = lengthofplaylist();
    int i=0;
    int arr[len]={0};

    while (i<len){
        int random =rand()% len+1;
        if (!search(arr,i,random)){
            arr[i]=random;
            i++;
            playsong(random);//play the song command
        }
    }

}

void playsong (int position){
        
        playlist* current= head;
        playlist* prev = NULL;
        
        //traversing
        int count=1;
        while (count<position){
            prev= current;
            current= current->next;
            count++;
        }

    cout<< current->sgname<<endl;


}


//DEVKRITI

int lengthofplaylist(){
    
    playlist*temp=head;
    int len=0;

    while(temp!=NULL){
        len=len+1;
        temp=temp->next;
}

    return len;

}
//display lyrics of a song 
 void lyrics(){

    playlist* temp=head;
    while(temp!=NULL)
    {
       
    string filename; 
    filename=temp->sgname+".txt";
    
    ifstream file(filename);
    if(file){
    vector<string> lyrics;
    string word;
    while(getline(file,word)){
        lyrics.push_back(word);
}
    file.close();
    cout<<temp->sgname<<" "<<"lyrics"<<endl;
    for(const string&lyric:lyrics)
    {
        cout<<lyric<<" ";
    }
    }
    else{
        cout<<"lyrics for "<<filename<<"not found";
    }
    //system("pause");
    temp=temp->next;
    }
 }
//returns sngname
  playlist* findsong(const string& song)

    {
        playlist*temp=head;
        while(temp!=NULL)
        {
            if(temp->sgname==song){
                return temp;
            }
            
            temp=temp->next;
        }
            return NULL;
    }

    


    //loop a song
 void loopsong(const  string&song,int count) {
        playlist* sngname=findsong(song);
        while(count>-1){
            count--;
        if (sngname != NULL && count!=-1) {
            sngname->savenext=sngname->next;
            sngname->saveprev=sngname->prev;
            sngname->next = sngname;
            sngname->prev = sngname;
            cout<<song<<endl;
        }
        sngname->next=sngname->savenext;
            sngname->prev=sngname->saveprev;                                                                                                                                                                                                                                                                                                                                                                                                                                     
        
            

        
        
        }
         sngname->next=sngname->savenext;
            sngname->prev=sngname->saveprev;

    }




};



   

  

    

int main(){

    
} 


