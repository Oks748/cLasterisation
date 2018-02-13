//---------------------------------------------------------------------------
#ifndef klas1H
#define klas1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <vector.h>
//---------------------------------------------------------------------------
class P{ public: vector<unsigned int> x; TColor colour;};
class vids{ public: float distance; int gg;};//dlja vidstanej
//---------------------------------------------------------------------------
class TComparison : public TForm
{
__published:	// IDE-managed Components
        TPageControl *Sheets;
        TTabSheet *dimension2;
        TPaintBox *kanva;
        TTabSheet *dimensionN;
        TMemo *Memokmeans;
        TLabel *LabelN;
        TEdit *EditN;
        TLabel *LabelK;
        TEdit *EditK;
        TLabel *LabelNP;
        TEdit *EditNP;
        TButton *Count;
        TButton *RandomPoint;
        TButton *Clear;
        TMemo *Messages;
        TLabel *LabelSusidy;
        TEdit *EditSusidy;
        TButton *ClustTochka;
        TLabel *Labelstat;

        void __fastcall FormPaint(TObject *Sender);
        void __fastcall kanvaMouseUp(TObject *Sender, TMouseButton Button,
                                   TShiftState Shift, int X, int Y);
        void __fastcall RandomPointClick(TObject *Sender);
        void __fastcall CountClick(TObject *Sender);
        void __fastcall ClustTochkaClick(TObject *Sender);
        void __fastcall SheetsChange(TObject *Sender);
        void __fastcall EditNPChange(TObject *Sender);
        void __fastcall EditKChange(TObject *Sender);
        void __fastcall EditNChange(TObject *Sender);
        void __fastcall ClearClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TComparison(TComponent* Owner);

        vector<P> koord; //vsi tochky | N-rozmir
        vector<P> centry; //pochatkovi dlja kmeans
        unsigned int k, n, np, ksusidy, ki; //kilkist klasteriv, Rprostoru, nTochok
        vector<P> previouscentry;
        vector< vector<P> > kser;//mnozhyna klasteriv "kmeans" | kser[k]
        unsigned int end;
        bool fg; //chy natysnuly knopku
        P pointkNN; //rombik
        vector<vids> vidstani;

        bool correct(); ///perevirka edits
        void randoming();  //random tochky
        void choosecenters();//vybir pochatkovyh centriv
        void bindpoints(); //rozkyd po klasteram kmeans
        float dosqrt(P,P);
        void centermass();
        void vyvidkmeans(); //output kmeans
        void vyvidkanva(unsigned int, unsigned int); //na kanvu "kmeans"
        bool correctsus(); //perevirka kilkosti susidiv
        void kNearest(); //kNN
        void vyvidkNN(); // output kNN
        void cleaning();  //Clear kanvas\memos\vectors
};
//---------------------------------------------------------------------------
extern PACKAGE TComparison *Comparison;
//---------------------------------------------------------------------------
#endif
