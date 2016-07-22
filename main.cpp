#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

int file();
void change();
void translatn();
void atmfunc();
void changnginit();
void pdb(int beg,int fin,string proteinName,  int loopTurn, string fileName );
void atmgen();
int hel(int low, int high);
void shts(int difference, string filename);
void arrng();
void get(string s, ofstream & outfile);
void sheets1();




struct infoHel
{
    string kindrec, nanuprec,lnanuprec;
    int noseq,lInoseq;

};

struct infoSh
{
    string kindrec,nanuprec,lnanuprec;
    int noseq, lInoseq;
};


struct infoa
{
    string a;
    double no, frstone,secondone, thirdone;




};

struct ran
{
    int beging,fin;
};

vector<infoHel> ord;

vector<infoSh> ord1;

vector<infoa> ord3;

vector<infoa> somthng;

vector<infoa> somthngelse;

vector<string> prgrms;

vector<ran> range;

vector<ran> somethingmore;



int beg=0,fin=0,prob=0,atombeg=0,atomEnd=0,pat=0,previousbeg=0;


int main()
{
    string s,filename;
    ifstream inFile;
    ofstream outFile;
    int difference,choice;
    choice=1;
    int valid;

    remove("in.pdb");

pat=file();



cout<<">";




cout<<"pat"<<pat;



   if(pat==1)
   {
       cout<<"pat"<<pat;
    atmfunc();

    translatn();


    change();

    changnginit();



   }



    return 0;
}




void change()
{

    ifstream inFile;
    ofstream outFile;
    string line;
    inFile.open("in.pdb");
    outFile.open("file.pdb");
    int i=0;




        while(!inFile.eof()&&getline(inFile,line))

        {

       if(line.substr(0,1)=="!" || line.substr(0,1)=="^")
          {


          }
          else
          {
           string noseq=line.substr(22,4);
           string cAlpha=line.substr(12,4);
           string frstone=line.substr(30,8);
           string secondone=line.substr(38,8);
           string thirdone=line.substr(46,8);
           string chainIdentifier=line.substr(21,1);
          int number=stoi(noseq.c_str());

              if(number>=range[i+1].beging && number<=range[i+1].fin )
              {
              double x=somthng[i].frstone+stod(frstone);
              double y=somthng[i].secondone+stod(secondone);
              double z=somthng[i].thirdone+stod(thirdone);



                  string str = to_string (x);
                  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
                  string dec=str.substr(str.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str=str+"0";
                  for(int i=0;i<=(frstone.length()-str.length()+1);i++)
                  str=" "+str;
                  if( str.length()>8)
                    str.erase(0,1);


                   string str1 = to_string (y);
                  str1.erase ( str1.find_last_not_of('0') + 1, std::string::npos );
                    dec=str1.substr(str1.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str1=str1+"0";
                   for(int i=0;i<=(secondone.length()-str1.length()+1);i++)
                    str1=" "+str1;
                    if( str1.length()>8)
                    str1.erase(0,1);

                 string str2 = to_string (z);
                  str2.erase ( str2.find_last_not_of('0') + 1, std::string::npos );
                  dec=str2.substr(str2.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str2=str2+"0";
                  for(int i=0;i<=(thirdone.length()-str2.length()+1);i++)
                  str2=" "+str2;
                  if( str2.length()>8)
                    str2.erase(0,1);







                  line.replace(line.find(frstone), frstone.length(),str );
                  line.replace(line.find(secondone), secondone.length(),str1);
                  line.replace(line.find(thirdone), thirdone.length(),str2);

                if(number==(range[i+1].fin-1))
                {
                    i++;


                }



              }

        }
        outFile<<line<<endl;

        }




}









void translatn()
{

    double x1 = (ord3[0].frstone), y1 = (ord3[0].secondone), z1 = (ord3[0].thirdone),


			x2 = (ord3[1].frstone),y2 = (ord3[1].secondone), z2 = (ord3[1].thirdone),

			r = sqrt((pow((x2-x1),2)) + (pow((y2-y1),2)) + (pow((z2-z1),2))), theta = atan((y2-y1)/(x2-x1)),si = acos((z2-z1)/r);




        for(int i=3;i<ord3.size();i=i+2){

        infoa aData1;


        double x3 = (ord3[i-1].frstone),
				y3 = (ord3[i-1].secondone),
				z3 = (ord3[i-1].thirdone);

        aData1.a=ord3[i].a;
        aData1.no=ord3[i].no;
        double x4 = (ord3[i].frstone),
				y4 = (ord3[i].secondone),
				z4 = (ord3[i].thirdone);


        double R = sqrt((pow((x4-x3),2)) + (pow((y4-y3),2)) + (pow((z4-z3),2)));

        double x5 = R * cos(theta) * sin(si),
				y5 = R * sin(theta) * sin(si),
				z5 = R * cos(si);

        x5 += x1;
        y5 += y1;
        z5 += z1;


        ord3[i].frstone = x5;
        ord3[i].secondone = y5;
        ord3[i].thirdone = z5;

        aData1.frstone=x5-x4;
        aData1.secondone=y5-y4;
        aData1.thirdone=z5-z4;



        somthngelse.push_back(aData1);


    }

}

void changnginit()
{


    ifstream inFile;
    ofstream outFile;
    string line;

    inFile.open("twoalp.pdb");
    outFile.open("result.pdb");
    while(!inFile.eof() && getline(inFile,line))
      {

          if(line.substr(0,5)=="!ATOM")
          {


          string noseq=line.substr(23,4);
          string cAlpha=line.substr(13,4);
          string frstone=line.substr(31,8);
          string secondone=line.substr(39,8);
          string thirdone=line.substr(47,8);
          string chainIdentifier=line.substr(22,1);


          string markerAtom="!ATOM";

          string atomString="ATOM";

           line.replace(line.find(markerAtom), markerAtom.length(),atomString);



          for(int i=2;i<ord3.size();i=i+2 )
          {
              if(ord3[i].no==atoi(noseq.c_str()) && cAlpha==" CA ")
              {


                  string str = to_string (ord3[0].frstone);
                  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
                  string dec=str.substr(str.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str=str+"0";
                  for(int i=0;i<=(frstone.length()-str.length()+1);i++)
                  str=" "+str;
                  if( str.length()>8)
                    str.erase(0,1);


                   string str1 = to_string (ord3[0].secondone);
                  str1.erase ( str1.find_last_not_of('0') + 1, std::string::npos );
                    dec=str1.substr(str1.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str1=str1+"0";
                   for(int i=0;i<=(secondone.length()-str1.length()+1);i++)
                    str1=" "+str1;
                    if( str1.length()>8)
                    str1.erase(0,1);

                 string str2 = to_string (ord3[0].thirdone);
                  str2.erase ( str2.find_last_not_of('0') + 1, std::string::npos );
                  dec=str2.substr(str2.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str2=str2+"0";
                  for(int i=0;i<=(thirdone.length()-str2.length()+1);i++)
                  str2=" "+str2;
                  if( str2.length()>8)
                    str2.erase(0,1);



                  line.replace(line.find(frstone), frstone.length(),str );
                  line.replace(line.find(secondone), secondone.length(),str1);
                  line.replace(line.find(thirdone), thirdone.length(),str2);

                  break;

              }
          }







          }

           if(line.substr(0,5)=="^ATOM")
          {




          string noseq=line.substr(23,4);
          string cAlpha=line.substr(13,4);
          string frstone=line.substr(31,8);
          string secondone=line.substr(39,8);
          string thirdone=line.substr(47,8);
          string chainIdentifier=line.substr(22,1);

          string markerAtom="^ATOM";

          string atomString="ATOM";
          line.replace(line.find(markerAtom), markerAtom.length(),atomString);



          for(int i=3;i<ord3.size();i=i+2 )
          {
              if(ord3[i].no==atoi(noseq.c_str()) && cAlpha==" CA ")
              {



                  string str = to_string (ord3[i].frstone);
                  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
                  string dec=str.substr(str.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str=str+"0";
                     str = (str.substr(0,str.find(".")) + str.substr(str.find("."),4));
                  for(int i=0;i<=(frstone.length()-str.length()+1);i++)
                  str=" "+str;
                  if( str.length()>8)
                    str.erase(0,1);


                   string str1 = to_string (ord3[i].secondone);
                  str1.erase ( str1.find_last_not_of('0') + 1, std::string::npos );
                  dec=str1.substr(str1.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str1=str1+"0";
                    str1 = (str1.substr(0,str1.find(".")) + str1.substr(str1.find("."),4));
                   for(int i=0;i<=(secondone.length()-str1.length()+1);i++)
                    str1=" "+str1;
                    if( str1.length()>8)
                    str1.erase(0,1);

                 string str2 = to_string (ord3[i].thirdone);
                  str2.erase ( str2.find_last_not_of('0') + 1, std::string::npos );
                  dec=str2.substr(str2.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str2=str2+"0";
                    str2 = (str2.substr(0,str2.find(".")) + str2.substr(str2.find("."),4));
                  for(int i=0;i<=(thirdone.length()-str2.length()+1);i++)
                  str2=" "+str2;
                  if( str2.length()>8)
                    str2.erase(0,1);

                  line.replace(line.find(frstone), frstone.length(),str );
                  line.replace(line.find(secondone), secondone.length(),str1);
                  line.replace(line.find(thirdone), thirdone.length(),str2);

                  break;

              }
          }


          }


	   outFile<<line<<endl;


      }


}



void atmfunc()
{
     infoa aData1;






    for(int i=2;i<ord3.size();i=i+2)
    {

        aData1.a=ord3[i].a;
        aData1.no=ord3[i].no;
        aData1.frstone=ord3[0].frstone-ord3[i].frstone;
        aData1.secondone=ord3[0].secondone-ord3[i].secondone;
        aData1.thirdone=ord3[0].thirdone-ord3[i].thirdone;


        ord3[i].frstone=ord3[i].frstone+ aData1.frstone;
        ord3[i].secondone=ord3[i].secondone+ aData1.secondone;
        ord3[i].thirdone=ord3[i].thirdone+ aData1.thirdone;



        ord3[i+1].frstone=ord3[i+1].frstone+ aData1.frstone;
        ord3[i+1].secondone=ord3[i+1].secondone+ aData1.secondone;
        ord3[i+1].thirdone=ord3[i+1].thirdone+ aData1.thirdone;





       cout<<endl;
       somthng.push_back(aData1);




    }






}


void atmgen()
{


         ifstream inFile;
         string temp,marker,word,word1,s;
         int number;

         inFile.open("in.pdb");

         while(!inFile.eof())
         {
             infoa aData1;
             infoa aData2;


             getline(inFile,s);
             marker=s.substr(0,1);
              if(marker=="!" || marker=="^")
              {


                temp=s.substr(23,4);
                marker=s.substr(0,1);
                number=atoi(temp.c_str());

                  if(number==atombeg && marker=="!" )
                   {
                     word=s.substr(1,4);
                     aData1.a=word;
                     word=s.substr(23,4);
                     aData1.no=atoi(word.c_str());

                     word=s.substr(31,8);
                     aData1.frstone=stod(word.c_str());

                     word=s.substr(39,8);
                     aData1.secondone=stod(word.c_str());

                     word=s.substr(47,8);
                     aData1.thirdone=stod(word.c_str());





                   }

               if(number==atomEnd&& marker=="^" )
                {

                  word=s.substr(1,4);
                  aData2.a=word;
                  word=s.substr(23,4);
                  aData2.no=atoi(word.c_str());

                  word=s.substr(31,8);
                  aData2.frstone=stod(word.c_str());

                  word=s.substr(39,8);
                  aData2.secondone=stod(word.c_str());

                  word=s.substr(47,8);
                  aData2.thirdone=stod(word.c_str());


                 ord3.push_back(aData1);
                 ord3.push_back(aData2);

               }



             }





        }









}





void pdb(int beg,int fin,string proteinName,  int loopTurn, string fileName )
{
    ofstream outFile,outFile1;
    ifstream inFile,inFile1;
    string s,s1,word,temp,word1,filename,fName,chainIdentifier;
    int number=0;




   filename=proteinName+"_"+to_string(beg)+"_"+to_string(loopTurn)+".pdb";

   cout<<endl<<"PDB"<<filename<<endl;


    inFile.open(fileName.c_str());
    outFile.open(filename.c_str());
    outFile1.open("in.pdb",ios::app);
    while(!inFile.eof() && prob==0)
    {
        getline(inFile,s);
        if(!s.empty())
        {
            word=s.substr(0,4);
            word1=s.substr(0,6);
            chainIdentifier=s.substr(21,1);
           if(word!="ATOM" && word1!="HETATM")
           {
             outFile<<s<<endl;
           }

          if(word=="ATOM")
          {
            temp=s.substr(22,4);
            number=atoi(temp.c_str());
            word1=s.substr(12,4);
            if(number==atombeg && word1==" CA " && chainIdentifier=="A")
                outFile1<<"!";
            if(number==atomEnd && word1==" CA " && chainIdentifier=="A")
                outFile1<<"^";
            if(number >=beg && number <=fin)
            {
            outFile<<s<<endl ;
            }

            if(number >=beg && number <=fin && word1==" CA "  && chainIdentifier=="A")
            {
            outFile1<<s<<endl;
            }
         }

        }
        else if(s.empty())
        {
         outFile<<endl<<s;
        }
    }

    atmgen();










}


int hel(int low, int high)
{
    for(int i=0;i<ord.size();i++)
    {
        if(ord[i].noseq>=low&&ord[i].lInoseq<=high)
        {
            cout<<endl<<"!error";
            prob=1;
            return 0;

        }


    }

    return 1;

}


void shts(int difference, string filename)
{
    int dif=0;
    int count;
    int countMatches=0;

    for(int i=0;i<ord1.size();i++)
    {

        dif=(ord1[i+1].noseq-ord1[i].lInoseq-1);

        if(dif==difference)
        {

            count=hel(ord1[i].lInoseq,ord1[i+1].noseq);
            if(count==1)
            {
                beg=ord1[i].noseq;
                fin=ord1[i+1].lInoseq;
                atombeg=ord1[i].lInoseq;
                atomEnd=ord1[i+1].noseq;
                countMatches++;




                pdb(beg,fin,ord1[i].nanuprec,dif,filename);
                previousbeg=ord1[i].noseq;

                ran rangeOfSheets;
                rangeOfSheets.beging=beg;
                rangeOfSheets.fin=ord1[i+1].noseq;
                range.push_back(rangeOfSheets);

               rangeOfSheets.beging=ord1[i+1].noseq;
                rangeOfSheets.fin=ord1[i+1].lInoseq;
                somethingmore.push_back(rangeOfSheets);




            }


        }
        else
        {


        }

    }


}


void arrng()
{
    int i,j,value=0,tempNumber=0;
    string tempString;

    for(i=0;i<ord.size();i++)
    {
        value=ord[i].noseq;
         for(j=0;j<ord.size()-1;j++)
         {
        if(ord[j+1].noseq<ord[j].noseq)
        {



             tempString=ord[j].nanuprec;
            ord[j].nanuprec=ord[j+1].nanuprec;
            ord[j+1].nanuprec=tempString;

            tempNumber=ord[j].noseq;
            ord[j].noseq=ord[j+1].noseq;
            ord[j+1].noseq=tempNumber;


            tempString=ord[j].lnanuprec;
            ord[j].lnanuprec=ord[j+1].lnanuprec;
            ord[j+1].lnanuprec=tempString;

           tempNumber=ord[j].lInoseq;
            ord[j].lInoseq=ord[j+1].lInoseq;
            ord[j+1].lInoseq=tempNumber;
        }
         }


    }
}


void sheets1()
{

    int i,j,value=0,tempNumber=0;
    string tempString;


    for(i=0;i<ord1.size();i++)
    {
        value=ord1[i].noseq;
         for(j=0;j<ord1.size()-1;j++)
         {
        if(ord1[j+1].noseq<ord1[j].noseq)
        {



             tempString=ord1[j].nanuprec;
            ord1[j].nanuprec=ord1[j+1].nanuprec;
            ord1[j+1].nanuprec=tempString;

            tempNumber=ord1[j].noseq;
            ord1[j].noseq=ord1[j+1].noseq;
            ord1[j+1].noseq=tempNumber;


            tempString=ord1[j].lnanuprec;
            ord1[j].lnanuprec=ord1[j+1].lnanuprec;
            ord1[j+1].lnanuprec=tempString;

           tempNumber=ord1[j].lInoseq;
            ord1[j].lInoseq=ord1[j+1].lInoseq;
            ord1[j+1].lInoseq=tempNumber;
        }
         }


    }

}





void get(string s, ofstream & outfile)
{
    string word;
    infoHel data;
    infoSh sData;

    int value;
     word=s.substr(0,5);
        if(word=="HELIX")
        {
            outfile<<endl;
            data.kindrec=word;
            outfile<<word<<" "<<endl;
            word=s.substr(15,3);
            outfile<<word<<" "<<endl;
            data.nanuprec=word;
            word=s.substr(21,4);
            outfile<<word<<" "<<endl;
            data.noseq=atoi(word.c_str());
            word=s.substr(27,3);
            outfile<<word<<" "<<endl;
            data.lnanuprec=word;
            word=s.substr(33,4);
            outfile<<word<<" "<<endl;
            data.lInoseq=atoi(word.c_str());

            ord.push_back(data);

        }
        else if(word=="SHEET")
        {
            outfile<<endl;
            sData.kindrec=word;
            outfile<<word<<" "<<endl;
            word=s.substr(17,3);
            outfile<<word<<" "<<endl;
            sData.nanuprec=word;
            word=s.substr(22,4);
            outfile<<word<<" "<<endl;
            sData.noseq=atoi(word.c_str());
            word=s.substr(28,3);
            outfile<<word<<" "<<endl;
            sData.lnanuprec=word;
            word=s.substr(33,4);
            outfile<<word<<" "<<endl;
            sData.lInoseq=atoi(word.c_str());

            ord1.push_back(sData);

        }

            word=s.substr(0,4);


        arrng();//arranging it
        sheets1();




}


int file()
{
	string s,filename;
    ifstream inFile;
    ofstream outFile;
    int difference,choice;
    choice=1;
    int valid;
	   while(choice)
    {
         cout<<endl<<"File? "<<"give name"<<" "<<endl;
        cin>>filename;
        inFile.open(filename.c_str());
        if(inFile.fail())
        {
        cout<<endl<<" Wrong file"<<endl;
        exit(0);

        }
        else
        prgrms.push_back(filename);
        cout<<"always 1 to continue giving more files 0 to terminate";
         cout<<endl<<endl<<"multiple files Y-1 or N-0 :";
         cin>>valid;

       if(valid==1)
        choice=1;
       else if(valid==0)
      {
        choice=0;

         break;

      }

     else
     {

        choice=0;

        break;

    }

    inFile.close();

    }

    loop:cout<<endl<<endl<<"alignment? Y-1 or No-0 :";
    cin>>valid;
        if(valid==1)
        {


        pat=1;
        }
       else if(valid==0)
      {
          pat=0;
      }



    cout<<endl<<endl<<"loop difference :";
    cin>>difference;



    for(int i=0;i<prgrms.size();i++)
    {
        filename=prgrms[i];
        inFile.close();

       inFile.open(filename.c_str());
       outFile.open("output.txt");


     if(inFile.fail())
     {
       cout<<endl<<" file not found "<<endl;
       exit(0);

     }

    else
    {
        while(!inFile.eof())
       {
        getline(inFile,s);
        get(s, outFile);//fetching
       }

    }


	}
	shts(difference, filename);//ord1 data cal
    ord.erase(ord.begin(),ord.end());
    ord1.erase(ord1.begin(),ord1.end());
cout<<"pat"<<pat<<endl;
return pat;
}
