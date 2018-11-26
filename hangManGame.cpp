#include<iostream>
#include<cstdlib>
#include<unistd.h>
using namespace std;
int sizeofstr(string s);
int comparing(string usedchar, char guess);
int checking(string city,char input[],int sizee);
int main()
{
    char again ='y',guess;
    string cities[5]={"pakistan","india","china","japan","canada"},usedchar;
    int sizee,val,decission,warning;
    for(;;)
    {
        usedchar="";
        warning=0;
        if(again=='y')
        {
            system("clear");
            cout<<" =& Hang Man &= "<<endl;
            cout<<" ______________"<<endl<<endl;
            val=rand()%4;
            sizee=sizeofstr(cities[val]);
            char input[sizee];
            for(int i=0;i<sizee;i++)
            {
                input[i]='-';
            }
            for(;;)
            {

                if(warning == 6)
                {
                    cout<<"\n =& You lost &="<<endl<<endl;
                    cout<<" [X_X]\n";
                    cout<<"---|---"<<endl;
                    cout<<"   |"<<endl;
                    cout<<"  / \\"<<endl;
                    cout<<" /   \\"<<endl<<endl;
                    break;
                }
                else if(checking(cities[val],input,sizee)==1)
                {
                    cout<<"\n\n Your Guess it right : ";
                    for(int i=0;i<sizee;i++)
                    {
                        cout<<input[i]<<" ";
                    }
                    cout<<"\n\n ^^ Congrats you win ^^"<<endl<<endl;
                    break;
                }
                else
                {
                    cout<<"\n Guess the city name : ";
                    for(int i=0;i<sizee;i++)
                    {
                        cout<<input[i]<<" ";
                    }
                    cout<<"\n Enter your guess : ";cin>>guess;
                    if(comparing(usedchar,guess)==1)
                    {
                        cout<<"\n ++ You have entered the letter before ++"<<endl;
                    }
                    else
                    {
                        if(comparing(cities[val],guess)==1)
                        {
                            usedchar=usedchar+guess;
                            for(int i=0;i<sizee;i++)
                            {
                                if(cities[val][i]==guess)
                                {
                                    input[i]=guess;
                                }
                            }
                        }
                        else
                        {
                            cout<<" << SORRY This Character Is Not A Part Of The Name >>"<<endl;
                            if(warning == 1){
                            	cout<<" [0_0]\n";
                            	cout<<"   |"<<endl<<endl;
                            }
                            if(warning ==2){
                            cout<<" [0_0]\n";
                            cout<<"   |"<<endl;
                            cout<<"   |"<<endl<<endl;
                            }
                            if(warning ==3){
                            cout<<" [0_0]\n";
                            cout<<"---|"<<endl;
                            cout<<"   |"<<endl<<endl;
                            }
                            if(warning ==4){
                            cout<<" [0_0]\n";
                            cout<<"---|---"<<endl;
                            cout<<"   |"<<endl<<endl;
                            }
                            if(warning ==5){
                            cout<<" [0_0]\n";
                            cout<<"---|---"<<endl;
                            cout<<"   |"<<endl;
                            cout<<"  /"<<endl;
                            cout<<" /"<<endl<<endl;
                            }
                            warning++;
                        }
                    }
                }
            }
            cout<<"\n want to play again (y/n) ? ";cin>>again;
        }
        else
        {
            break;
        }
    }
    cout<<"\n\n <** Thank you for playing **>\n\n";
    return 0;
}

int sizeofstr(string s)
{
    int counter;
    for(counter=0;s[counter] != '\0';counter++){}
    return counter;
}

int comparing(string usedchar, char guess)
{
    int check=0;
    for(int i=0;i<sizeofstr(usedchar);i++)
    {
        if(usedchar[i]==guess)
        {
            check++;
        }
    }
    if(check>0)
            return 1;
        else
            return 0;
}
int checking(string city,char input[],int sizee)
{
    int check = 0;
    for(int i=0;i<sizee;i++)
    {
        if(city[i]==input[i])
            check++;
    }
    if(check==sizee)
        return 1;
    else
        return 0;
}




