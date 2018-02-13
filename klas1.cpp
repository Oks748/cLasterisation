//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop
#include "klas1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TComparison *Comparison;
//---------------------------------------------------------------------------
__fastcall TComparison::TComparison(TComponent* Owner) : TForm(Owner){}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//differForm colors of paintboxes
void __fastcall TComparison::FormPaint(TObject *Sender)
{
    Sheets->ActivePage = dimension2;
    kanva->Canvas->Brush->Color = clWhite;
    kanva->Canvas->Rectangle(0,0,kanva->Width,kanva->Height);
    ClustTochka->Enabled = false;
}
//---------------------------------------------------------------------------
bool TComparison::correct()//tilky naturalni chysla>0cili || perevirka Edits
{                          
    bool b = 0;
    for(int i = 1; i <= EditN->Text.Length(); i++)//tilky naturalni chysla>0cili
    {
        if(EditN->Text[1]== '0') {b = 0; break;}
        else if(isdigit(EditN->Text[i])) b = 1;
        else {b = 0; break;}
    }
    if( b == 0 )
    {
        ShowMessage("Розмірність повинна бути натуральним числом!");
    }
    else
    {
        n = StrToInt(EditN->Text);
        for(int i = 1; i <= EditK->Text.Length(); i++)//tilky naturalni chysla>0cili
        {
            if(EditK->Text[1]== '0') {b = 0; break;}
            else if(isdigit(EditK->Text[i])) b = 1;
            else {b = 0; break;}
        }
        if( b == 0 )
        {
            ShowMessage("Кількість кластерів повинна бути натуральним числом!");
        }
        else
        {
            k = StrToInt(EditK->Text);
            for(int i = 1; i <= EditNP->Text.Length(); i++)//tilky naturalni chysla>0cili
            {
                if(EditNP->Text[1]== '0') {b = 0; break;}
                else if(isdigit(EditNP->Text[i])) b = 1;
                else {b = 0; break;}
            }
            if( b == 0 )
            {
               ShowMessage("Кількість точок повинна бути натуральним числом!");
            }
            else
            {
                np = StrToInt(EditNP->Text);
                return 1;
            }
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TComparison::SheetsChange(TObject *Sender){ cleaning(); }
//---------------------------------------------------------------------------
void __fastcall TComparison::EditNPChange(TObject *Sender){ cleaning(); }
//---------------------------------------------------------------------------
bool TComparison::correctsus()
{
    bool b = 0;
    for(int i = 1; i <= EditSusidy->Text.Length(); i++)//tilky naturalni chysla>0cili
    {
        if(EditSusidy->Text[1]== '0') {b = 0; break;}
        else if(isdigit(EditSusidy->Text[i])) b = 1;
        else {b = 0; break;}
    }
    if( b == 0 )
    {
        ShowMessage("Кількість сусідів повинна бути натуральним числом!");
        return 0;
    }
    else
    {
        if((unsigned int)StrToInt(EditSusidy->Text) > koord.size())
        {
            ShowMessage("Кількість сусідів повинна бути меншою ніж кількість точок!");
            return 0;
        }
        else
        {
            ksusidy = StrToInt(EditSusidy->Text);
            return 1;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TComparison::EditKChange(TObject *Sender)
{
    kser.clear();
    kanva->Canvas->Brush->Color = clWhite;
    kanva->Canvas->Rectangle(0,0,kanva->Width,kanva->Height);
    Messages->Clear();
    for(unsigned int j = 0; j < koord.size(); j++)//peredacha na "draw"
    {
        vyvidkanva(koord[j].x[0],koord[j].x[1]);
    }
    ClustTochka->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TComparison::EditNChange(TObject *Sender){ cleaning(); }
//---------------------------------------------------------------------------
void __fastcall TComparison::kanvaMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(fg == true)
    {
        n = 2;
        pointkNN.x.resize(2);
        pointkNN.x[0] = X;  pointkNN.x[1] = Y;

        int R = 4;
        TPoint romb[4];
        romb[0].x = X-R; romb[0].y = Y;
        romb[1].x = X;   romb[1].y = Y-R;
        romb[2].x = X+R; romb[2].y = Y;
        romb[3].x = X;   romb[3].y = Y+R;
        kanva->Canvas->Brush->Color = clRed;
        kanva->Canvas->Polygon(romb,3);
    }
    else
    {
        n = 2;
        P ppoint; ppoint.x.push_back(X); ppoint.x.push_back(Y);
        koord.push_back(ppoint);
        vyvidkanva(X,Y); //vidkladennja tochok na "kmeans"
    }
}
//---------------------------------------------------------------------------
void TComparison::vyvidkanva(unsigned int x, unsigned int y)
{
   //pokaz tochok na "kmeans"
   kanva->Canvas->Pen->Color = clBlack;
   kanva->Canvas->Pen->Width = 1;
   kanva->Canvas->MoveTo(x, y);
   kanva->Canvas->LineTo(x, y);

   int R = 2;
   kanva->Canvas->Brush->Color = clBlack;
   kanva->Canvas->Ellipse(x-R, y-R, x+R, y+R);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TComparison::RandomPointClick(TObject *Sender)
{
    if(correct()) //if pravylnyj vvid
    {
        randoming();//na kanvi
    }    
}
//---------------------------------------------------------------------------
void TComparison::randoming()//generuvannja tochok N-rozmir
{
    P ppoint;    ppoint.x.resize(n);  //n - kilkist koordynat tochky
    for(unsigned int j = 0; j < np; j++)  //np- kilkist tochok
    {
        for(unsigned int i = 0; i < n; i++) //rozmir -> n-koordynat
        {
            ppoint.x[i] = (10+rand()%(kanva->Width-20)); //400->10~390
        }
        koord.push_back(ppoint); //N rozm | 2
    }

    if(Sheets->ActivePage == dimension2)
    {
        for(unsigned int j = 0; j < koord.size(); j++)//peredacha na "draw"
        {
            vyvidkanva(koord[j].x[0],koord[j].x[1]);
        }
    }
    else if(Sheets->ActivePage == dimensionN)
    {
        Memokmeans->Clear();
        //vyvid vsih tochok
        Memokmeans->Lines->Add("Точки");
        for(unsigned int j = 0; j < koord.size(); j++)
        {
            String aa = IntToStr(j+1)+" p( ";
            for(unsigned int i = 0; i < n; i++)
            {
                if(i == n-1)aa+=IntToStr(koord[j].x[i]);
                else aa+=IntToStr(koord[j].x[i])+", ";
            }
            aa+=" )";
            Memokmeans->Lines->Add(aa);
        }
        Memokmeans->Lines->Add("Кількість точок "+IntToStr(koord.size()));
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TComparison::CountClick(TObject *Sender)
{
    fg = true;//tochka
    if(correct()) //if pravylnyj vvid
    {
        if(koord.empty())
        {
            ShowMessage("Немає точок!");
        }
        else
        {
            RandomPoint->Enabled = false;
            Count->Enabled = false;
            if(Sheets->ActivePage == dimension2)
            {//tilky koly n = 2
                choosecenters();
                for(unsigned int g = 0; g < k; g++)
                {
                    previouscentry.push_back(centry[g]);//dlja kmeans
                }
                end = 0;
                bindpoints();
            }
            else
            {
                choosecenters();
                for(unsigned int g = 0; g < k; g++)
                {
                    previouscentry.push_back(centry[g]);//dlja kmeans
                }
                end = 0;
                bindpoints();// -->kmeans
            }
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//vybir pochatkovyh centriv centrojidiv
void TComparison::choosecenters()
{
    centry.clear();
    for(unsigned int j = 0; j < k; j++)//----cykl po kilkosti centriv  | k
    {
            bool t;
            unsigned int bb;
            do
            {
                t = 0;
                unsigned int gh = rand()%(koord.size());
                centry.push_back(koord[gh]);
                for(unsigned int gg = 0; gg < j; gg++)
                {
                    bb = 0;
                    for(unsigned int i = 0; i <centry[j].x.size(); i++)
                    {   //po koordynatam
                        if( centry[j].x[i] == centry[gg].x[i]) bb++;
                    }
                    if(bb == centry[j].x.size())
                    { centry.pop_back(); t = 1; }//vsi x[i] spivpadajut
                }
            }while(t);
    }//cykl po centrah

    if(Sheets->ActivePage == dimension2)
    {
        Messages->Lines->Add("Кількість точок "+IntToStr(koord.size()));
        Messages->Lines->Add("Початкові центри");
        for(unsigned int j = 0; j < k; j++)//vyvid pochatkovyh centriv
        {
            String sdf = IntToStr(j+1)+"("+centry[j].x[0]+","+centry[j].x[1]+")";
            Messages->Lines->Add(sdf);
        }
    }
    else
    {
        Memokmeans->Lines->Add("-----------------------------");
        Memokmeans->Lines->Add("Початкові центри");
        for(unsigned int j = 0; j < k; j++)//vyvid pochatkovyh centriv
        {
            String sdf = IntToStr(j+1)+"("+centry[j].x[0]+","+centry[j].x[1]+")";
            Memokmeans->Lines->Add(sdf);
        }
    }
}
//---------------------------------------------------------------------------
float TComparison::dosqrt( P ks, P kd ) //koordynaty  v tochkah
{
    float sum = 0;
    for(unsigned int i = 0; i < n; i++)
    {
       sum = sum + (ks.x[i]-kd.x[i])*(ks.x[i]-kd.x[i]); //po koordynatam
    }
    return abs(sum);
}
//---------------------------------------------------------------------------
//zv'jazka tochok | rozkyd po klasteram
void TComparison::bindpoints()
{
    //nulovi elementy == vybrani pochatkovi centry
    for(unsigned int g = 0; g < k; g++)
    {
        vector<P> pp;//perekydna komirka
        pp.push_back(previouscentry[g]); //velychyna previouscentry????????
        kser.push_back(pp);
        pp.clear();
    }
    for(unsigned int j = 0; j < koord.size(); j++)//po vsim tochkam
    {
        float dist = dosqrt(kser[0][0], koord[j]);
        vector< P > *kh = &kser[0];// v 1st klaster
        for(unsigned int g = 1; g < k; g++)//mozhe v inshyj klaster
        {
	    float neardist = dosqrt(kser[g][0], koord[j]);
            if(dist > neardist)
            {
                dist = neardist;
                kh = &kser[g];
            }// search the nearest cluster and push
	}
        (*kh).push_back(koord[j]);// a->b == (*a).b.
    }
    centermass();
}
//---------------------------------------------------------------------------
//centr mass
void TComparison::centermass()
{
    for(unsigned int g = 0; g < k; g++)//ruh po centram klasteriv
    {
        vector<unsigned int> cm(n, 0); //dlja kozhnoji koordynaty n
        for(unsigned int j = 0; j < kser[g].size(); j++)//po vsim tochkam pidklusteru
        {
            for(unsigned int i = 0; i < n; i++)
            {
                cm[i] = cm[i] + kser[g][j].x[i];
            }
        }
        P ppoint;
        for(unsigned int i = 0; i < n; i++)
        {
            ppoint.x.push_back(((unsigned int)cm[i]/kser[g].size()));
        }   //rozrahovanyj novyj centr mass
        previouscentry[g] = kser[g][0];
        kser[g][0] = ppoint; //new centers
        ppoint.x.clear();
    }
    //chy dali zv'jazuvaty, chy ni ? | tak pry pershomy prohodi
    unsigned int t = 0;
    for(unsigned int g = 0; g < k; g++)
    {
        unsigned int bb = 0;
        for(unsigned int i = 0; i < n; i++)//1 tochka-centr
        {  //koordynaty tochky-centru } jih je n shtuk
           if( kser[g][0].x[i] == previouscentry[g].x[i]) bb++;
        }
        if(bb == n) t++;//vsi x[i] spivpadajut
    }
    end++;
    if(t != k && end < 1000)
    {   // t -> kilkist spivpavshyh centriv
        for(unsigned int g = 0; g < k; g++) previouscentry[g] = kser[g][0];
        kser.clear();
        bindpoints();
    }
    else vyvidkmeans();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TComparison::vyvidkmeans() //vyvid na kanvu i u Memokmeans
{
    if(Sheets->ActivePage == dimension2)
    {
        Messages->Lines->Add("--------------------");
        Messages->Lines->Add("Кінцеві центри кластерів та кількість точок в кластерах");
        for(unsigned int g = 0; g < k; g++)
        {
            String sdf = IntToStr(g+1)+"_"+"("+kser[g][0].x[0]+","
                          +kser[g][0].x[1]+")_"+IntToStr(kser[g].size());
            Messages->Lines->Add(sdf);
        }
        Messages->Lines->Add("Ітерацій "+IntToStr(end));

        for(unsigned int g = 0; g < k; g++)//for move in cluster
        {
            //dlja centriv
            kanva->Canvas->Pen->Width = 1;
            kanva->Canvas->MoveTo(kser[g][0].x[0], kser[g][0].x[1]);
            kanva->Canvas->LineTo(kser[g][0].x[0], kser[g][0].x[1]);
            int R = 6;
            kser[g][0].colour = TColor(RGB(rand()%255,rand()%255,rand()%255));
            kanva->Canvas->Brush->Color = kser[g][0].colour;
            kanva->Canvas->Rectangle(kser[g][0].x[0]-R,kser[g][0].x[1]-R,kser[g][0].x[0]+R,kser[g][0].x[1]+R);

            //vsi inshi tochky
            for(unsigned int j = 1; j < kser[g].size(); j++)//po vsim tochkam pidklusteru
            {
                kanva->Canvas->Pen->Color = clBlack;
                kanva->Canvas->Pen->Width = 1;
                kanva->Canvas->MoveTo(kser[g][j].x[0], kser[g][j].x[1]);
                kanva->Canvas->LineTo(kser[g][j].x[0], kser[g][j].x[1]);

                kser[g][j].colour = kser[g][0].colour;
                int R = 4;
                kanva->Canvas->Brush->Color = kser[g][j].colour;
                kanva->Canvas->Ellipse(kser[g][j].x[0]-R,kser[g][j].x[1]-R,kser[g][j].x[0]+R,kser[g][j].x[1]+R);
            }
        }
    }
    else
    {   //dimension N
        Memokmeans->Lines->Add("---------------------------------------------");
        Memokmeans->Lines->Add("Вивід кластерів, їх центрів та кількість об'єктів у кластері");
        for(unsigned int g = 0; g<kser.size(); g++)
        {
            Memokmeans->Lines->Add(IntToStr(g+1)+"-й кластер "+IntToStr(kser[g].size())+" точок");
            for(unsigned int j = 0; j < kser[g].size(); j++)
            {
                String aa = "  "+IntToStr(g+1)+"_"+IntToStr(j+1)+" p( ";
                for(unsigned int i = 0; i < kser[g][j].x.size(); i++)
                {
                    if(i == n-1)aa+=IntToStr(kser[g][j].x[i]);
                    else aa+=IntToStr(kser[g][j].x[i])+", ";
                }
                aa+=" )";
                if(j == 0) aa+= " центр";
                Memokmeans->Lines->Add(aa);
            }
        }
    }
    ClustTochka->Enabled = true;
}
//---------------------------------------------------------------------------
void TComparison::vyvidkNN()
{
    if(Sheets->ActivePage == dimension2)
    {
        //odna nova tochka
        //pointkNN.x[0]
        int R = 4;
        TPoint romb[4];
        romb[0].x = pointkNN.x[0]-R; romb[0].y = pointkNN.x[1];
        romb[1].x = pointkNN.x[0];   romb[1].y = pointkNN.x[1]-R;
        romb[2].x = pointkNN.x[0]+R; romb[2].y = pointkNN.x[1];
        romb[3].x = pointkNN.x[0];   romb[3].y = pointkNN.x[1]+R;
        kanva->Canvas->Brush->Color = pointkNN.colour;
        kanva->Canvas->Polygon(romb,3);
        Messages->Lines->Add("--------------------");
        Messages->Lines->Add("Точка потрапила в "+IntToStr(ki+1)+"-й кластер");
        pointkNN.x.clear();
    }
    else
    {
        Memokmeans->Lines->Add("---------------------------------------------");

        String aa = " p( ";
        for(unsigned int i = 0; i < pointkNN.x.size(); i++)
        {
            if(i == n-1)aa+=IntToStr(pointkNN.x[i]);
            else aa+=IntToStr(pointkNN.x[i])+", ";
        }
        aa+=" )";
        Memokmeans->Lines->Add(aa);

        Memokmeans->Lines->Add("Точка потрапила в "+IntToStr(ki+1)+"-й кластер");
        pointkNN.x.clear();
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TComparison::ClearClick(TObject *Sender){cleaning();}
//---------------------------------------------------------------------------
void TComparison::cleaning()
{
    kanva->Canvas->Brush->Color = clWhite;
    kanva->Canvas->Rectangle(0,0,kanva->Width,kanva->Height);
    Memokmeans->Clear();
    Messages->Clear();
    koord.clear();
    centry.clear();
    previouscentry.clear();
    kser.clear();
    end = 0;
    pointkNN.x.clear();
    ClustTochka->Enabled = false;
    RandomPoint->Enabled = true;
    Count->Enabled = true;
    vidstani.clear();
    fg = false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TComparison::kNearest() //algorithm k-nearest neighbours 1 tochka
{
    //vidstani.resize();
    for(unsigned int g = 0; g < k; g++)//po vsim klasteram
    {
        for(unsigned int j = 0; j < kser[g].size(); j++)//po vsim tochkam klasteru
        {
            vids pp;//perekydna komirka
            pp.distance = sqrt( dosqrt(kser[g][j], pointkNN));
            pp.gg = g;
            vidstani.push_back( pp );
	}
    }

    //sort(vidstany);
    for(unsigned int i = 0; i < vidstani.size(); i++)
    for(unsigned int j = i; j < vidstani.size(); j++)
    if(vidstani[i].distance > vidstani[j].distance)
    {   //po zrostannju
        float tmp = vidstani[i].distance;
        vidstani[i].distance = vidstani[j].distance ;
        vidstani[j].distance = tmp;
        int tmp2 = vidstani[i].gg;
        vidstani[i].gg = vidstani[j].gg;
        vidstani[j].gg = tmp2;

    }


    vector<unsigned int> lichylnyk(k,0); //vid 0 do k
    for(unsigned int d = 0; d < ksusidy; d++)
    {
       int gg2 = vidstani[d].gg;
       lichylnyk[gg2]++;// kser[g]+ golos
    }
    //vyvid golosiv
    if(Sheets->ActivePage == dimension2)
    {
        Messages->Lines->Add("-------------------");
        Messages->Lines->Add("Голоси");
        for(unsigned int j = 0; j < lichylnyk.size(); j++)//vyvid pochatkovyh centriv
        {
            Messages->Lines->Add(IntToStr(lichylnyk[j])+"_");
        }
    }
    unsigned int maxgolos = lichylnyk[0];
    ki = 0;
    for(unsigned int g = 0; g < lichylnyk.size(); g++)
    {
        if(lichylnyk[g] > maxgolos)
        {
            maxgolos = lichylnyk[g];
            ki = g;// indeks maxgolos  | jakyj klaster
        }
    }
    //zanesennja tochky v klaster
    pointkNN.colour = kser[ki][0].colour;
    kser[ki].push_back(pointkNN);
    lichylnyk.clear();
    vidstani.clear();
}
//----------------------------------------------------------------------------
void __fastcall TComparison::ClustTochkaClick(TObject *Sender)
{
    if(correctsus())
    {
        RandomPoint->Enabled = false;
        if(Sheets->ActivePage == dimension2)
        {
            if(pointkNN.x.empty())ShowMessage("Виберіть точку на канві!");
            else
            {
                kNearest();
                vyvidkNN();
            }
        }
        else
        {
            String aa;

            pointkNN.x.resize(n);
            //parsyty

            bool b = 0, bq = 0;
            unsigned int kn = 0;
            while( kn < n)
            {
                bq = InputQuery("Ввести","Введіть координату "+IntToStr(kn+1),aa);
                if(bq)
                {
                    b = 0;
                    for(int i = 1; i <= aa.Length(); i++)//tilky naturalni chysla>0cili
                    {
                    if(isdigit(aa[i])) b = 1;
                    else {b = 0; break;}
                    }
                    if( b == 0 )
                    {
                    ShowMessage("Координата повинна бути натуральним числом!");
                    }
                    else
                    {
                    pointkNN.x[kn] = StrToInt(aa);
                    kn++;
                    }
                }
                else break;
            }
            if(bq)
            {
                kNearest();
                vyvidkNN();
            }
        }
    }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

