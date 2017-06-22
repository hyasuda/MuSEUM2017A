void scan(){

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
  
  TGraphErrors* gr = new TGraphErrors();
  
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

      double count, vVref;
    
      for(int i=0; i<32; i++ ){

      count += B2C0ch[i]/pulse;
      // vVref += Vref2;


    gr->SetPoint( nn, Vref2, count );
    nn++;
      }

  }

  TCanvas* c1= new TCanvas("c1","c1",600,600);
  c1->SetGrid();
  //c1->SetLogy();
  gr->SetMarkerStyle(20);
  gr->Draw("AP");
  c1->Print("scan.pdf");
}
