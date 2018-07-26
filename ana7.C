void ana7(){
  ifstream ifs2("serial_Vop_ch_table.txt");
  ifstream ifs1("gainfitpow4rightloop.txt");
  ofstream ofs("gainVop.txt");
  Double_t a,b,c,d,e,f,g,h,i;
  while(ifs1>>a>>b>>c>>d>>e && ifs2>>f>>g>>h){
    i=g-52.37;
    ofs << i << " " << "\t" << c << " " << "\t" << b << endl;
  }
  ifstream ifs("gainVop.txt");
  vector<Double_t> x,y0,y1;
  Double_t xx,yy0,yy1;
  while(ifs>>xx>>yy0>>yy1){
    if(yy0>10){
      x.push_back(xx);
      y0.push_back(yy0);
      y1.push_back(yy1);
    }
  }
  ifs.close();
  Double_t* xpointer=&(x.at(0));
  Double_t* y0pointer=&(y0.at(0));
  Double_t* y1pointer=&(y1.at(0));
  TGraph* tg[2];
    tg[0] = new TGraph(x.size(),xpointer,y0pointer);
    tg[1] = new TGraph(x.size(),xpointer,y1pointer);
  TCanvas* c1 = new TCanvas("c1","",1800,900);
  c1->Draw();
  tg[0]->Draw("AP");
  tg[0]->SetMarkerStyle(20);
  tg[0]->SetTitle("p1perdV;dV;p1");
  c1->Print("p1perdV.png");
  TCanvas* c2 = new TCanvas("c2","",1800,900);
  c2->Draw();
  tg[1]->Draw("AP");
  tg[1]->SetMarkerStyle(20);
  tg[1]->SetTitle("p0perdV;dV;p0");
  c2->Print("p0perdV.png");
}
