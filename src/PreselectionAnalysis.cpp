#include "interface/PreselectionAnalysis.hpp"

void Preselection::Init()
{

    for ( string l : AllLabel()  ) {
        cout <<"[Preselection]::[Init]::[INFO] Boking Histo CutFlow_" <<l<<endl;

        Book( ("Preselection/CutFlow_"+ l ) .c_str(), ("CutFlow "+ l).c_str(),100,-.5,100-.5);
        GetHisto(("Preselection/CutFlow_"+l).c_str(),"")->GetXaxis()->SetBinLabel(1,"Total");
        //GetHisto(("Preselection/CutFlow_"+l).c_str(),"")->GetXaxis()->SetBinLabel(2,"N_{jets} #geq 3");
        //GetHisto(("Preselection/CutFlow_"+l).c_str(),"")->GetXaxis()->SetBinLabel(3,"N_{Bjets} #geq 1");
    }

}

int Preselection::analyze(Event*e,string systname)
{
#ifdef VERBOSE
    if(VERBOSE>0)cout<<"[Preselection]::[analyze]::[DEBUG] analyze event with syst: "<<systname<<endl;
#endif
    string label = "Preselection/CutFlow_" + GetLabel(e);

    if(e->weight() == 0. ) cout <<"[Preselection]::[analyze]::[INFO] Even Weight is NULL !!"<< e->weight() <<endl;

    Fill( label ,systname,0,e->weight());

    //if ( e->Njets() <3 ) return 1;
    //Fill( label ,systname,1,e->weight());

    //if ( e->Bjets() <1 ) return 1;
    //Fill( label,systname,2,e->weight());

    // ---  SF examples --
    //SetPtEtaSF("muon",100,1);
    //ApplySF("muon");
    //e->weight();
    // ----	
    return 0;
}
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4 
