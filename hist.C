void hist()
{

  int ndev=2161;
  //int ndev=4327;
  //int ndev=9973;
  TH1F* h=new TH1F("hash1","random array hash test",ndev,-0.5,ndev-0.5);
  TH1F* h2=new TH1F("hash2","random array hash test",ndev,-0.5,ndev-0.5);
  TH1F* h3=new TH1F("hash3","random array hash test",ndev,-0.5,ndev-0.5);
  TH1F* h4=new TH1F("hash4","random array hash test",ndev,-0.5,ndev-0.5);

  TH2F*  h2d=new TH2F("2d","map 1 vs. 2",2161,-0.5,2160.5,2161,-0.5,2160.5);
  TH2F*  h2d2=new TH2F("2d2","map 1 vs. 3",2161,-0.5,2160.5,2161,-0.5,2160.5);
  TH2F*  h2d3=new TH2F("2d3","map 1 vs. 4",2161,-0.5,2160.5,2161,-0.5,2160.5);
  TH2F*  h2d4=new TH2F("2d4","map 2 vs. 3",2161,-0.5,2160.5,2161,-0.5,2160.5);
  TH2F*  h2d5=new TH2F("2d5","map 2 vs. 4",2161,-0.5,2160.5,2161,-0.5,2160.5);
  TH2F*  h2d6=new TH2F("2d6","map 3 vs. 4",2161,-0.5,2160.5,2161,-0.5,2160.5);

  ifstream ifs;double x,y,z,w;

  ifs.open("double_test.dat");
  while(ifs>>x>>y>>z>>w){
    h->Fill(x);
    h2->Fill(y);
    h3->Fill(z);
    h4->Fill(w);

    h2d->Fill(y,x);
    h2d2->Fill(z,z);
    h2d3->Fill(w,x);
    h2d4->Fill(z,y);
    h2d5->Fill(w,y);
    h2d6->Fill(w,z);
    
  }
  ifs.close();
  TCanvas* c=new TCanvas("c1","hash",800,600);

  c->Divide(2,2);
  c->cd(1);  
  h->Draw();
  c->cd(2);
  h2->Draw();  
  c->cd(3);
  h3->Draw();  
  c->cd(4);
  h4->Draw();
  
  c->SaveAs("hash_hist.eps");
  c->SaveAs("hash_hist.png");

  
  TCanvas* c2=new TCanvas("c2","hash",800,600);
  gStyle->SetOptStat(kFALSE);
  c2->Divide(3,2);
  c2->cd(1);
  h2d->Draw("colz");
  c2->cd(2);
  h2d2->Draw("colz");
  c2->cd(3);
  h2d3->Draw("colz");
  c2->cd(4);
  h2d4->Draw("colz");
  c2->cd(5);
  h2d5->Draw("colz");
  c2->cd(6);
  h2d6->Draw("colz");
  c2->SaveAs("hash_hist_logo.eps");
  c2->SaveAs("hash_hist_logo.png");
  
  
}
