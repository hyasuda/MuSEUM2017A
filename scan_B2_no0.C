void scan_B2_no0(){

  double pulse;
  double Vref2;
  double Vref5;
  
  double B2C0ch[128];  
  double B2C1ch[128];  
  double B2C2ch[128];
  double B2C3ch[128];
  double B5C0ch[128];  
  double B5C1ch[128];  
  double B5C2ch[128];
  double B5C3ch[128];
  
  fstream fin;
  fin.open("scan_result.txt", ios::in);
  
  TGraphErrors* gr1 = new TGraphErrors();
  TGraphErrors* gr2 = new TGraphErrors();
  TGraphErrors* gr3 = new TGraphErrors();
  TGraphErrors* gr4 = new TGraphErrors();
  int nn = 0;
  
  while(1){
    if( fin.eof() ) break;

    fin >> pulse >> Vref2 >> Vref5;
      for(int i=0; i<128; i++){ fin >> B2C0ch[i]; }
      for(int i=0; i<128; i++){ fin >> B2C1ch[i]; }
      for(int i=0; i<128; i++){ fin >> B2C2ch[i]; }
      for(int i=0; i<128; i++){ fin >> B2C3ch[i]; }
      for(int i=0; i<128; i++){ fin >> B5C0ch[i]; }
      for(int i=0; i<128; i++){ fin >> B5C1ch[i]; }
      for(int i=0; i<128; i++){ fin >> B5C2ch[i]; }
      for(int i=0; i<128; i++){ fin >> B5C3ch[i]; }

      fin.close();

      double count;
    
      for(int i=0; i<32; i++ ){

      count += B2C0ch[i]/pulse;

    gr1->SetPoint( nn, Vref2, count );
    nn++;
      }

      for(int i=32; i<64; i++ ){

	count += B2C0ch[i]/pulse;

	gr2->SetPoint( nn, Vref2, count );
	nn++;
      }

      for(int i=64; i<96; i++ ){

	count += B2C0ch[i]/pulse;

	gr3->SetPoint( nn, Vref2, count );
	nn++;
      }

      for(int i=96; i<128; i++ ){

	count += B2C0ch[i]/pulse;

	gr4->SetPoint( nn, Vref2, count );
	nn++;
      }




  }

  TCanvas* c1= new TCanvas("c1","c1",1200,600);
  c1 -> Divide(4.1);
 
  gr1->SetMarkerStyle(20);
  c1->cd(1);
  c1->SetGrid();
  gr1->Draw("AP");

  gr2->SetMarkerStyle(20);
  c1->cd(2);
  gr2->Draw("AP");

  gr3->SetMarkerStyle(20);
  c1->cd(3);
  gr3->Draw("AP");

  gr4->SetMarkerStyle(20);
  c1->cd(4);
  gr4->Draw("AP");


  c1->Print("scan.pdf");
}
