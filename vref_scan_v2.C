#include<set>


void vref_scan( string filename = "scan_result.txt"){

    double pulse;
    double Vref2, Vref5;
    // int count2[512];
    // int count5[512];
    int count[1024];

    // const int board =   2;
    // const int cp    =   4;
    // const int ch    = 128;
    // const int div   =  128/32;
    // const int part  = 32;

    std::set<int> noisy2{};
    std::set<int> noisy5{};

    // noisy2.count(440); To count/classify noisy ch

    ifstream ifs(filename, std::ios::in);

    TCanvas* c1 = new TCanvas("c1","c1");
    TCanvas* c2 = new TCanvas("c2","c2");

    TGraphErrors* gref2 = new TGraphErrors("gref2","Board2:Channnel of Board2:Count/pulse");
    TGraphErrors* gref5 = new TGraphErrors("gref5","Board5:Channnel of Board5:Count/pulse");

    ifs >> pulse >> Vref2 >> Vref5;

    cout << "Pulse = " << pulse << endl;
    cout << "Vref2 = " << Vref2 << endl;
    cout << "Vref5 = " << Vref5 << endl;

    for(int i = 0 ; i < 1024 ; i++){
        ifs >> count[i];
        // cout << "Board2::" << i << "::" << count[i] << endl;
        // cout << "Board5::" << i << "::" << count[i+512] << endl;
        cout << count[i] << " " ;
    }

    cout << endl;

    // for(int i = 0 ; i < 512 ; i++){
    //     ifs >> count2[i];
    //     gref2->SetPoint(i,i,count2[i]);
    //     cout << "Board2::" << i << "::" << count2[i] << endl;
    // }

    // for(int i = 0 ; i < 512 ; i++){
    //     ifs >> count5[i];
    //     gref5->SetPoint(i,i,count2[i]);
    //     cout << "Board5::" << i << "::" << count2[i] << endl;
    // }

    for(int i = 0 ; i < 512 ; i++){
        gref2->SetPoint(i,i,count[i]/pulse);
        gref5->SetPoint(i,i,count[i+512]/pulse);
    }

    c1->cd();
    gref2->Draw();

    c2->cd();
    gref5->Draw();


}
