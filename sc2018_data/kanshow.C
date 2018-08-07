void kanshow(){
  char a[10];
  vector<double> b,c,x;
  double bb,cc;
  //cout << "test1" << endl;
  for(int filenum = 100;filenum <133;filenum++){
  ifstream ifs(Form("pemean%d.txt",filenum));
  //cout << "test2" << endl;
  while(!ifs.eof()){
  ifs>>a>>bb>>cc;
  //cout << a << " " << bb << " " << cc << endl;
  b.push_back(bb);
  c.push_back(cc);
  if(filenum<117){
  x.push_back(40000 + 125*(filenum-100));
  }
  if(filenum>117){
  x.push_back(40000 + 125*(116-filenum));
  cout << filenum << " " << bb << endl;
  }
  //cout << "test3" << endl;
 }
 Double_t* xpointer=&(x.at(0));
 Double_t* bpointer=&(b.at(0));
 Double_t* cpointer=&(c.at(0));
 //cout << c[0] << endl;
 TGraphErrors *tg = new TGraphErrors(x.size(),xpointer,bpointer,0,cpointer);
 tg -> Draw("AP");
}
}
