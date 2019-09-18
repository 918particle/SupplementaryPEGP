void plots(const char *fileTitle)
{
	//Globals
	gStyle->SetOptStat(0);
	Float_t lmargin = 0.1;
	Float_t rmargin = 0.1;
	Float_t bmargin = 0.1;
	Float_t tmargin = 0.05;
	Float_t xlow = 0.0;
	Float_t xhigh = 6.0;
	Float_t ylow = 0.0;
	Float_t yhigh = 6.0;
	Float_t standard_line_width = 2.0;
	Float_t standard_marker_style = 20.0;
	Float_t standard_marker_size = 2.0;
	Int_t fontCode = 82;
	Float_t tsize = 0.04;
	Float_t lsize = 0.04;
	Float_t toffsetx = 0.0;
	Float_t toffsety = 0.0;

	TFile *inFile = new TFile(fileTitle);
	TTree *eval_data = new TTree();
	inFile->GetObject("eval_data",eval_data);
	Int_t n = eval_data->GetEntries();

	UInt_t question = 0;
	eval_data->SetBranchAddress("question",&question);
	UInt_t N = 0;
	eval_data->SetBranchAddress("N",&N);
	Float_t mean = 0.0;
	eval_data->SetBranchAddress("mean",&mean);
	Float_t sd = 0.0;
	eval_data->SetBranchAddress("sd",&sd);
	UInt_t w1 = 0;
	eval_data->SetBranchAddress("w1",&w1);
	UInt_t w2 = 0;
	eval_data->SetBranchAddress("w2",&w2);
	UInt_t w3 = 0;
	eval_data->SetBranchAddress("w3",&w3);
	UInt_t w4 = 0;
	eval_data->SetBranchAddress("w4",&w4);
	UInt_t w5 = 0;
	eval_data->SetBranchAddress("w5",&w5);
	char course[8];
	eval_data->SetBranchAddress("course",&course);
	char year[8];
	eval_data->SetBranchAddress("year",&year);
	char semester[8];
	eval_data->SetBranchAddress("semester",&semester);

	TH1F *h_mark = new TH1F("h_mark","",10,xlow,xhigh);
	h_mark->GetXaxis()->SetRangeUser(xlow,xhigh);
	h_mark->GetYaxis()->SetRangeUser(ylow,yhigh);
	h_mark->GetXaxis()->SetTitle("Number of Times Taught");
	h_mark->GetYaxis()->SetTitle("Q25: Mean #pm Error in Mean");
	h_mark->GetXaxis()->SetTitleOffset(toffsetx);
	h_mark->GetYaxis()->SetTitleOffset(toffsety);
	h_mark->GetXaxis()->SetTitleSize(tsize);
	h_mark->GetYaxis()->SetTitleSize(tsize);
	h_mark->GetXaxis()->SetTitleFont(fontCode);
	h_mark->GetYaxis()->SetTitleFont(fontCode);
	h_mark->GetXaxis()->SetLabelFont(fontCode);
	h_mark->GetYaxis()->SetLabelFont(fontCode);
	h_mark->GetXaxis()->SetLabelSize(lsize);
	h_mark->GetYaxis()->SetLabelSize(lsize);

	// //=====Question 25 versus semester for PHYS135A/B.  m = number of times taught.=====//
	const Int_t m = 5;
	Float_t x[m];
	Float_t y[m];
	Float_t ex[m];
	Float_t ey[m];
	Int_t c = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="135A" || thisCourse=="135B") && question==25)
	// 	{
	// 		x[c] = (Float_t)c+1.0;
	// 		ex[c] = 0.0;
	// 		y[c] = mean;
	// 		ey[c] = sd/sqrt(N);
	// 		++c;
	// 	}
	// }
	// //Note: reversing order of simultaneously-taught Fall-2018 135A courses for clarity in figure.
	Float_t temp1 = 0.0;
	Float_t temp2 = 0.0;
	// temp1 = y[2];
	// temp2 = ey[2];
	// y[2] = y[3];
	// ey[2] = ey[3];
	// y[3] = temp1;
	// ey[3] = temp2;

	// TCanvas* Q25_algebra_based = new TCanvas("Q25_algebra_based","Q25_algebra_based",1200,1200);
	// TPad* p1 = new TPad("p1","p1",0.0,0.0,1.0,1.0);
	// p1->Draw();
	// p1->SetLeftMargin(lmargin);
	// p1->SetRightMargin(rmargin);
	// p1->SetTopMargin(tmargin);
	// p1->SetBottomMargin(bmargin);
	// p1->SetGridx();
	// p1->SetGridy();
	// p1->SetTickx();
	// p1->SetTicky();
	// p1->cd();
	// h_mark->Draw();

	// TGraphErrors *Q25 = new TGraphErrors(m,x,y,ex,ey);
	// Q25->SetMarkerStyle(standard_marker_style);
	// Q25->SetMarkerSize(standard_marker_size);
	// TF1 *Q25_algebra_based_fit = new TF1("Q25_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q25->Fit("Q25_algebra_based_fit","0");
	// Q25->Draw("P same");
	// Q25_algebra_based_fit->SetLineColor(kBlack);
	// Q25_algebra_based_fit->SetLineWidth(standard_line_width);
	// Q25_algebra_based_fit->Draw("same");
	// p1->Print("Q25_algebra_based.pdf");

	// //=====Question 25 versus semester for PHYS150/180.  m = number of times taught.=====//
	const Int_t m2 = 3;
	Float_t x2[m2];
	Float_t y2[m2];
	Float_t ex2[m2];
	Float_t ey2[m2];
	Int_t c2 = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="150" || thisCourse=="180") && question==25)
	// 	{
	// 		x2[c2] = (Float_t)c2+1.0;
	// 		ex2[c2] = 0.0;
	// 		y2[c2] = mean;
	// 		ey2[c2] = sd/sqrt(N)+0.001; //Give the 3rd data point non-zero standard deviation.
	// 		++c2;
	// 	}
	// }

	// TCanvas* Q25_calculus_based = new TCanvas("Q25_calculus_based","Q25_calculus_based",1200,1200);
	// TPad* p2 = new TPad("p2","p2",0.0,0.0,1.0,1.0);
	// p2->Draw();
	// p2->SetLeftMargin(lmargin);
	// p2->SetRightMargin(rmargin);
	// p2->SetTopMargin(tmargin);
	// p2->SetBottomMargin(bmargin);
	// p2->SetGridx();
	// p2->SetGridy();
	// p2->SetTickx();
	// p2->SetTicky();
	// p2->cd();
	// h_mark->Draw();

	// TGraphErrors *Q25_2 = new TGraphErrors(m2,x2,y2,ex2,ey2);
	// Q25_2->SetMarkerStyle(standard_marker_style);
	// Q25_2->SetMarkerSize(standard_marker_size);
	// TF1 *Q25_calculus_based_fit = new TF1("Q25_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q25_2->Fit("Q25_calculus_based_fit","0");
	// Q25_2->Draw("P same");
	// Q25_calculus_based_fit->SetLineColor(kBlack);
	// Q25_calculus_based_fit->SetLineWidth(standard_line_width);
	// Q25_calculus_based_fit->Draw("same");
	// p2->Print("Q25_calculus_based.pdf");

	//=====Question 16 versus semester for PHYS135A/B.  m = number of times taught.=====//
	// Float_t x3[m];
	// Float_t y3[m];
	// Float_t ex3[m];
	// Float_t ey3[m];
	// c = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="135A" || thisCourse=="135B") && question==16)
	// 	{
	// 		x3[c] = (Float_t)c+1.0;
	// 		ex3[c] = 0.0;
	// 		y3[c] = mean;
	// 		ey3[c] = sd/sqrt(N)+0.01;
	// 		++c;
	// 	}
	// }
	// //Note: reversing order of simultaneously-taught Fall-2018 135A courses for clarity in figure.
	// temp1 = y3[2];
	// temp2 = ey3[2];
	// y3[2] = y3[3];
	// ey3[2] = ey3[3];
	// y3[3] = temp1;
	// ey3[3] = temp2;

	// TCanvas* Q16_algebra_based = new TCanvas("Q16_algebra_based","Q16_algebra_based",1200,1200);
	// TPad* p3 = new TPad("p3","p3",0.0,0.0,1.0,1.0);
	// p3->Draw();
	// p3->SetLeftMargin(lmargin);
	// p3->SetRightMargin(rmargin);
	// p3->SetTopMargin(tmargin);
	// p3->SetBottomMargin(bmargin);
	// p3->SetGridx();
	// p3->SetGridy();
	// p3->SetTickx();
	// p3->SetTicky();
	// p3->cd();
	// h_mark->GetYaxis()->SetTitle("Q16: Mean #pm Error in Mean");
	// h_mark->Draw();

	// TGraphErrors *Q16 = new TGraphErrors(m,x3,y3,ex3,ey3);
	// Q16->SetMarkerStyle(standard_marker_style);
	// Q16->SetMarkerSize(standard_marker_size);
	// TF1 *Q16_algebra_based_fit = new TF1("Q16_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q16->Fit("Q16_algebra_based_fit","0");
	// Q16->Draw("P same");
	// Q16_algebra_based_fit->SetLineColor(kBlack);
	// Q16_algebra_based_fit->SetLineWidth(standard_line_width);
	// Q16_algebra_based_fit->Draw("same");
	// p3->Print("Q16_algebra_based.pdf");

	//=====Question 16 versus semester for PHYS150/180.  m = number of times taught.=====//
	// Float_t x4[m2];
	// Float_t y4[m2];
	// Float_t ex4[m2];
	// Float_t ey4[m2];
	// c2 = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="150" || thisCourse=="180") && question==16)
	// 	{
	// 		x4[c2] = (Float_t)c2+1.0;
	// 		ex4[c2] = 0.0;
	// 		y4[c2] = mean;
	// 		ey4[c2] = sd/sqrt(N)+0.01;
	// 		++c2;
	// 	}
	// }

	// TCanvas* Q16_calculus_based = new TCanvas("Q16_calculus_based","Q16_calculus_based",1200,1200);
	// TPad* p4 = new TPad("p4","p4",0.0,0.0,1.0,1.0);
	// p4->Draw();
	// p4->SetLeftMargin(lmargin);
	// p4->SetRightMargin(rmargin);
	// p4->SetTopMargin(tmargin);
	// p4->SetBottomMargin(bmargin);
	// p4->SetGridx();
	// p4->SetGridy();
	// p4->SetTickx();
	// p4->SetTicky();
	// p4->cd();
	// h_mark->Draw();

	// TGraphErrors *Q16_2 = new TGraphErrors(m2,x4,y4,ex4,ey4);
	// Q16_2->SetMarkerStyle(standard_marker_style);
	// Q16_2->SetMarkerSize(standard_marker_size);
	// TF1 *Q16_calculus_based_fit = new TF1("Q16_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q16_2->Fit("Q16_calculus_based_fit","0");
	// Q16_2->Draw("P same");
	// Q16_calculus_based_fit->SetLineColor(kBlack);
	// Q16_calculus_based_fit->SetLineWidth(standard_line_width);
	// Q16_calculus_based_fit->Draw("same");
	// p4->Print("Q16_calculus_based.pdf");

	// //=====Question 17 versus semester for PHYS135A/B.  m = number of times taught.=====//
	// Float_t x5[m];
	// Float_t y5[m];
	// Float_t ex5[m];
	// Float_t ey5[m];
	// c = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="135A" || thisCourse=="135B") && question==17)
	// 	{
	// 		x5[c] = (Float_t)c+1.0;
	// 		ex5[c] = 0.0;
	// 		y5[c] = mean;
	// 		ey5[c] = sd/sqrt(N)+0.01;
	// 		++c;
	// 	}
	// }

	// TCanvas* Q17_algebra_based = new TCanvas("Q17_algebra_based","Q17_algebra_based",1200,1200);
	// TPad* p5 = new TPad("p5","p5",0.0,0.0,1.0,1.0);
	// p5->Draw();
	// p5->SetLeftMargin(lmargin);
	// p5->SetRightMargin(rmargin);
	// p5->SetTopMargin(tmargin);
	// p5->SetBottomMargin(bmargin);
	// p5->SetGridx();
	// p5->SetGridy();
	// p5->SetTickx();
	// p5->SetTicky();
	// p5->cd();
	// h_mark->GetYaxis()->SetTitle("Q17: Mean #pm Error in Mean");
	// h_mark->Draw();

	// TGraphErrors *Q17 = new TGraphErrors(m,x5,y5,ex5,ey5);
	// Q17->SetMarkerStyle(standard_marker_style);
	// Q17->SetMarkerSize(standard_marker_size);
	// TF1 *Q17_algebra_based_fit = new TF1("Q17_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q17->Fit("Q17_algebra_based_fit","0");
	// Q17->Draw("P same");
	// Q17_algebra_based_fit->SetLineColor(kBlack);
	// Q17_algebra_based_fit->SetLineWidth(standard_line_width);
	// Q17_algebra_based_fit->Draw("same");
	// p5->Print("Q17_algebra_based.pdf");

	// //=====Question 17 versus semester for PHYS150/180.  m = number of times taught.=====//
	// Float_t x6[m2];
	// Float_t y6[m2];
	// Float_t ex6[m2];
	// Float_t ey6[m2];
	// c2 = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="150" || thisCourse=="180") && question==17)
	// 	{
	// 		x6[c2] = (Float_t)c2+1.0;
	// 		ex6[c2] = 0.0;
	// 		y6[c2] = mean;
	// 		ey6[c2] = sd/sqrt(N)+0.01;
	// 		++c2;
	// 	}
	// }

	// TCanvas* Q17_calculus_based = new TCanvas("Q17_calculus_based","Q17_calculus_based",1200,1200);
	// TPad* p6 = new TPad("p6","p6",0.0,0.0,1.0,1.0);
	// p6->Draw();
	// p6->SetLeftMargin(lmargin);
	// p6->SetRightMargin(rmargin);
	// p6->SetTopMargin(tmargin);
	// p6->SetBottomMargin(bmargin);
	// p6->SetGridx();
	// p6->SetGridy();
	// p6->SetTickx();
	// p6->SetTicky();
	// p6->cd();
	// h_mark->Draw();

	// TGraphErrors *Q17_2 = new TGraphErrors(m2,x6,y6,ex6,ey6);
	// Q17_2->SetMarkerStyle(standard_marker_style);
	// Q17_2->SetMarkerSize(standard_marker_size);
	// TF1 *Q17_calculus_based_fit = new TF1("Q17_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q17_2->Fit("Q17_calculus_based_fit","0");
	// Q17_2->Draw("P same");
	// Q17_calculus_based_fit->SetLineColor(kBlack);
	// Q17_calculus_based_fit->SetLineWidth(standard_line_width);
	// Q17_calculus_based_fit->Draw("same");
	// p6->Print("Q17_calculus_based.pdf");

	// //=====Question 15 versus semester for PHYS135A/B.  m = number of times taught.=====//
	// Float_t x7[m];
	// Float_t y7[m];
	// Float_t ex7[m];
	// Float_t ey7[m];
	// c = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="135A" || thisCourse=="135B") && question==15)
	// 	{
	// 		x7[c] = (Float_t)c+1.0;
	// 		ex7[c] = 0.0;
	// 		y7[c] = mean;
	// 		ey7[c] = sd/sqrt(N)+0.01;
	// 		++c;
	// 	}
	// }

	// temp1 = y7[0];
	// temp2 = ey7[0];
	// y7[0] = y7[1];
	// ey7[0] = ey7[1];
	// y7[1] = temp1;
	// ey7[1] = temp2;

	// TCanvas* Q15_algebra_based = new TCanvas("Q15_algebra_based","Q15_algebra_based",1200,1200);
	// TPad* p10 = new TPad("p10","p10",0.0,0.0,1.0,1.0);
	// p10->Draw();
	// p10->SetLeftMargin(lmargin);
	// p10->SetRightMargin(rmargin);
	// p10->SetTopMargin(tmargin);
	// p10->SetBottomMargin(bmargin);
	// p10->SetGridx();
	// p10->SetGridy();
	// p10->SetTickx();
	// p10->SetTicky();
	// p10->cd();
	// h_mark->GetYaxis()->SetTitle("Q15: Mean #pm Error in Mean");
	// h_mark->Draw();

	// TGraphErrors *Q15 = new TGraphErrors(m,x7,y7,ex7,ey7);
	// Q15->SetMarkerStyle(standard_marker_style);
	// Q15->SetMarkerSize(standard_marker_size);
	// TF1 *Q15_algebra_based_fit = new TF1("Q15_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q15->Fit("Q15_algebra_based_fit","0");
	// Q15->Draw("P same");
	// Q15_algebra_based_fit->SetLineColor(kBlack);
	// Q15_algebra_based_fit->SetLineWidth(standard_line_width);
	// Q15_algebra_based_fit->Draw("same");
	// p10->Print("Q15_algebra_based.pdf");

	// //=====Question 15 versus semester for PHYS150/180.  m = number of times taught.=====//
	// Float_t x8[m2];
	// Float_t y8[m2];
	// Float_t ex8[m2];
	// Float_t ey8[m2];
	// c2 = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="150" || thisCourse=="180") && question==15)
	// 	{
	// 		x8[c2] = (Float_t)c2+1.0;
	// 		ex8[c2] = 0.0;
	// 		y8[c2] = mean;
	// 		ey8[c2] = sd/sqrt(N)+0.01;
	// 		++c2;
	// 	}
	// }

	// TCanvas* Q15_calculus_based = new TCanvas("Q15_calculus_based","Q15_calculus_based",1200,1200);
	// TPad* p11 = new TPad("p11","p11",0.0,0.0,1.0,1.0);
	// p11->Draw();
	// p11->SetLeftMargin(lmargin);
	// p11->SetRightMargin(rmargin);
	// p11->SetTopMargin(tmargin);
	// p11->SetBottomMargin(bmargin);
	// p11->SetGridx();
	// p11->SetGridy();
	// p11->SetTickx();
	// p11->SetTicky();
	// p11->cd();
	// h_mark->Draw();

	// TGraphErrors *Q15_2 = new TGraphErrors(m2,x8,y8,ex8,ey8);
	// Q15_2->SetMarkerStyle(standard_marker_style);
	// Q15_2->SetMarkerSize(standard_marker_size);
	// TF1 *Q15_calculus_based_fit = new TF1("Q15_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q15_2->Fit("Q15_calculus_based_fit","0");
	// Q15_2->Draw("P same");
	// Q15_calculus_based_fit->SetLineColor(kBlack);
	// Q15_calculus_based_fit->SetLineWidth(standard_line_width);
	// Q15_calculus_based_fit->Draw("same");
	// p11->Print("Q15_calculus_based.pdf");

	// //=====Question 14 versus semester for PHYS135A/B.  m = number of times taught.=====//
	// Float_t x9[m];
	// Float_t y9[m];
	// Float_t ex9[m];
	// Float_t ey9[m];
	// c = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="135A" || thisCourse=="135B") && question==14)
	// 	{
	// 		x9[c] = (Float_t)c+1.0;
	// 		ex9[c] = 0.0;
	// 		y9[c] = mean;
	// 		ey9[c] = sd/sqrt(N)+0.01;
	// 		++c;
	// 	}
	// }

	// temp1 = y9[2];
	// temp2 = ey9[2];
	// y9[2] = y9[3];
	// ey9[2] = ey9[3];
	// y9[3] = temp1;
	// ey9[3] = temp2;

	// TCanvas* Q14_algebra_based = new TCanvas("Q14_algebra_based","Q14_algebra_based",1200,1200);
	// TPad* p12 = new TPad("p12","p12",0.0,0.0,1.0,1.0);
	// p12->Draw();
	// p12->SetLeftMargin(lmargin);
	// p12->SetRightMargin(rmargin);
	// p12->SetTopMargin(tmargin);
	// p12->SetBottomMargin(bmargin);
	// p12->SetGridx();
	// p12->SetGridy();
	// p12->SetTickx();
	// p12->SetTicky();
	// p12->cd();
	// h_mark->GetYaxis()->SetTitle("Q14: Mean #pm Error in Mean");
	// h_mark->Draw();

	// TGraphErrors *Q14 = new TGraphErrors(m,x9,y9,ex9,ey9);
	// Q14->SetMarkerStyle(standard_marker_style);
	// Q14->SetMarkerSize(standard_marker_size);
	// TF1 *Q14_algebra_based_fit = new TF1("Q14_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q14->Fit("Q14_algebra_based_fit","0");
	// Q14->Draw("P same");
	// Q14_algebra_based_fit->SetLineColor(kBlack);
	// Q14_algebra_based_fit->SetLineWidth(standard_line_width);
	// Q14_algebra_based_fit->Draw("same");
	// p12->Print("Q14_algebra_based.pdf");

	// // //=====Question 14 versus semester for PHYS150/180.  m = number of times taught.=====//
	// Float_t x10[m2];
	// Float_t y10[m2];
	// Float_t ex10[m2];
	// Float_t ey10[m2];
	// c2 = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="150" || thisCourse=="180") && question==14)
	// 	{
	// 		x10[c2] = (Float_t)c2+1.0;
	// 		ex10[c2] = 0.0;
	// 		y10[c2] = mean;
	// 		ey10[c2] = sd/sqrt(N)+0.01;
	// 		++c2;
	// 	}
	// }

	// TCanvas* Q14_calculus_based = new TCanvas("Q14_calculus_based","Q14_calculus_based",1200,1200);
	// TPad* p13 = new TPad("p13","p13",0.0,0.0,1.0,1.0);
	// p13->Draw();
	// p13->SetLeftMargin(lmargin);
	// p13->SetRightMargin(rmargin);
	// p13->SetTopMargin(tmargin);
	// p13->SetBottomMargin(bmargin);
	// p13->SetGridx();
	// p13->SetGridy();
	// p13->SetTickx();
	// p13->SetTicky();
	// p13->cd();
	// h_mark->Draw();

	// TGraphErrors *Q14_2 = new TGraphErrors(m2,x10,y10,ex10,ey10);
	// Q14_2->SetMarkerStyle(standard_marker_style);
	// Q14_2->SetMarkerSize(standard_marker_size);
	// TF1 *Q14_calculus_based_fit = new TF1("Q14_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q14_2->Fit("Q14_calculus_based_fit","0");
	// Q14_2->Draw("P same");
	// Q14_calculus_based_fit->SetLineColor(kBlack);
	// Q14_calculus_based_fit->SetLineWidth(standard_line_width);
	// Q14_calculus_based_fit->Draw("same");
	// p13->Print("Q14_calculus_based.pdf");

	// //=====Question 12 versus semester for PHYS135A/B.  m = number of times taught.=====//
	// Float_t x11[m];
	// Float_t y11[m];
	// Float_t ex11[m];
	// Float_t ey11[m];
	// c = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="135A" || thisCourse=="135B") && question==12)
	// 	{
	// 		x11[c] = (Float_t)c+1.0;
	// 		ex11[c] = 0.0;
	// 		y11[c] = mean;
	// 		ey11[c] = sd/sqrt(N)+0.01;
	// 		++c;
	// 	}
	// }

	// TCanvas* Q12_algebra_based = new TCanvas("Q12_algebra_based","Q12_algebra_based",1200,1200);
	// TPad* p14 = new TPad("p14","p14",0.0,0.0,1.0,1.0);
	// p14->Draw();
	// p14->SetLeftMargin(lmargin);
	// p14->SetRightMargin(rmargin);
	// p14->SetTopMargin(tmargin);
	// p14->SetBottomMargin(bmargin);
	// p14->SetGridx();
	// p14->SetGridy();
	// p14->SetTickx();
	// p14->SetTicky();
	// p14->cd();
	// h_mark->GetYaxis()->SetTitle("Q12: Mean #pm Error in Mean");
	// h_mark->Draw();

	// TGraphErrors *Q12 = new TGraphErrors(m,x11,y11,ex11,ey11);
	// Q12->SetMarkerStyle(standard_marker_style);
	// Q12->SetMarkerSize(standard_marker_size);
	// TF1 *Q12_algebra_based_fit = new TF1("Q12_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q12->Fit("Q12_algebra_based_fit","0");
	// Q12->Draw("P same");
	// Q12_algebra_based_fit->SetLineColor(kBlack);
	// Q12_algebra_based_fit->SetLineWidth(standard_line_width);
	// Q12_algebra_based_fit->Draw("same");
	// p14->Print("Q12_algebra_based.pdf");

	// // //=====Question 12 versus semester for PHYS150/180.  m = number of times taught.=====//
	// Float_t x12[m2];
	// Float_t y12[m2];
	// Float_t ex12[m2];
	// Float_t ey12[m2];
	// c2 = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="150" || thisCourse=="180") && question==12)
	// 	{
	// 		x12[c2] = (Float_t)c2+1.0;
	// 		ex12[c2] = 0.0;
	// 		y12[c2] = mean;
	// 		ey12[c2] = sd/sqrt(N)+0.01;
	// 		++c2;
	// 	}
	// }

	// TCanvas* Q12_calculus_based = new TCanvas("Q12_calculus_based","Q12_calculus_based",1200,1200);
	// TPad* p15 = new TPad("p15","p15",0.0,0.0,1.0,1.0);
	// p15->Draw();
	// p15->SetLeftMargin(lmargin);
	// p15->SetRightMargin(rmargin);
	// p15->SetTopMargin(tmargin);
	// p15->SetBottomMargin(bmargin);
	// p15->SetGridx();
	// p15->SetGridy();
	// p15->SetTickx();
	// p15->SetTicky();
	// p15->cd();
	// h_mark->Draw();

	// TGraphErrors *Q12_2 = new TGraphErrors(m2,x12,y12,ex12,ey12);
	// Q12_2->SetMarkerStyle(standard_marker_style);
	// Q12_2->SetMarkerSize(standard_marker_size);
	// TF1 *Q12_calculus_based_fit = new TF1("Q12_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q12_2->Fit("Q12_calculus_based_fit","0");
	// Q12_2->Draw("P same");
	// Q12_calculus_based_fit->SetLineColor(kBlack);
	// Q12_calculus_based_fit->SetLineWidth(standard_line_width);
	// Q12_calculus_based_fit->Draw("same");
	// p15->Print("Q12_calculus_based.pdf");

	// //=====Question 19 versus semester for PHYS135A/B.  m = number of times taught.=====//
	// Float_t x11[m];
	// Float_t y11[m];
	// Float_t ex11[m];
	// Float_t ey11[m];
	// c = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="135A" || thisCourse=="135B") && question==19)
	// 	{
	// 		x11[c] = (Float_t)c+1.0;
	// 		ex11[c] = 0.0;
	// 		y11[c] = mean;
	// 		ey11[c] = sd/sqrt(N)+0.01;
	// 		++c;
	// 	}
	// }

	// temp1 = y11[2];
	// temp2 = ey11[2];
	// y11[2] = y11[3];
	// ey11[2] = ey11[3];
	// y11[3] = temp1;
	// ey11[3] = temp2;

	// TCanvas* Q19_algebra_based = new TCanvas("Q19_algebra_based","Q19_algebra_based",1200,1200);
	// TPad* p14 = new TPad("p14","p14",0.0,0.0,1.0,1.0);
	// p14->Draw();
	// p14->SetLeftMargin(lmargin);
	// p14->SetRightMargin(rmargin);
	// p14->SetTopMargin(tmargin);
	// p14->SetBottomMargin(bmargin);
	// p14->SetGridx();
	// p14->SetGridy();
	// p14->SetTickx();
	// p14->SetTicky();
	// p14->cd();
	// h_mark->GetYaxis()->SetTitle("Q19: Mean #pm Error in Mean");
	// h_mark->Draw();

	// TGraphErrors *Q12 = new TGraphErrors(m,x11,y11,ex11,ey11);
	// Q12->SetMarkerStyle(standard_marker_style);
	// Q12->SetMarkerSize(standard_marker_size);
	// TF1 *Q12_algebra_based_fit = new TF1("Q12_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q12->Fit("Q12_algebra_based_fit","0");
	// Q12->Draw("P same");
	// Q12_algebra_based_fit->SetLineColor(kBlack);
	// Q12_algebra_based_fit->SetLineWidth(standard_line_width);
	// Q12_algebra_based_fit->Draw("same");
	// p14->Print("Q19_algebra_based.pdf");

	// // //=====Question 19 versus semester for PHYS150/180.  m = number of times taught.=====//
	// Float_t x12[m2];
	// Float_t y12[m2];
	// Float_t ex12[m2];
	// Float_t ey12[m2];
	// c2 = 0;

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	if((thisCourse=="150" || thisCourse=="180") && question==19)
	// 	{
	// 		x12[c2] = (Float_t)c2+1.0;
	// 		ex12[c2] = 0.0;
	// 		y12[c2] = mean;
	// 		ey12[c2] = sd/sqrt(N)+0.01;
	// 		++c2;
	// 	}
	// }

	// TCanvas* Q12_calculus_based = new TCanvas("Q19_calculus_based","Q19_calculus_based",1200,1200);
	// TPad* p15 = new TPad("p15","p15",0.0,0.0,1.0,1.0);
	// p15->Draw();
	// p15->SetLeftMargin(lmargin);
	// p15->SetRightMargin(rmargin);
	// p15->SetTopMargin(tmargin);
	// p15->SetBottomMargin(bmargin);
	// p15->SetGridx();
	// p15->SetGridy();
	// p15->SetTickx();
	// p15->SetTicky();
	// p15->cd();
	// h_mark->Draw();

	// TGraphErrors *Q12_2 = new TGraphErrors(m2,x12,y12,ex12,ey12);
	// Q12_2->SetMarkerStyle(standard_marker_style);
	// Q12_2->SetMarkerSize(standard_marker_size);
	// TF1 *Q12_calculus_based_fit = new TF1("Q12_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	// Q12_2->Fit("Q12_calculus_based_fit","0");
	// Q12_2->Draw("P same");
	// Q12_calculus_based_fit->SetLineColor(kBlack);
	// Q12_calculus_based_fit->SetLineWidth(standard_line_width);
	// Q12_calculus_based_fit->Draw("same");
	// p15->Print("Q19_calculus_based.pdf");

	//=====Question 20 versus semester for PHYS135A/B.  m = number of times taught.=====//
	Float_t x11[m];
	Float_t y11[m];
	Float_t ex11[m];
	Float_t ey11[m];
	c = 0;

	for(Int_t i=0;i<n;++i)
	{
		eval_data->GetEntry(i);
		string thisCourse(course);
		if((thisCourse=="135A" || thisCourse=="135B") && question==20)
		{
			x11[c] = (Float_t)c+1.0;
			ex11[c] = 0.0;
			y11[c] = mean;
			ey11[c] = sd/sqrt(N)+0.01;
			++c;
		}
	}

	temp1 = y11[2];
	temp2 = ey11[2];
	y11[2] = y11[3];
	ey11[2] = ey11[3];
	y11[3] = temp1;
	ey11[3] = temp2;

	TCanvas* Q19_algebra_based = new TCanvas("Q19_algebra_based","Q19_algebra_based",1200,1200);
	TPad* p14 = new TPad("p14","p14",0.0,0.0,1.0,1.0);
	p14->Draw();
	p14->SetLeftMargin(lmargin);
	p14->SetRightMargin(rmargin);
	p14->SetTopMargin(tmargin);
	p14->SetBottomMargin(bmargin);
	p14->SetGridx();
	p14->SetGridy();
	p14->SetTickx();
	p14->SetTicky();
	p14->cd();
	h_mark->GetYaxis()->SetTitle("Q20: Mean #pm Error in Mean");
	h_mark->Draw();

	TGraphErrors *Q12 = new TGraphErrors(m,x11,y11,ex11,ey11);
	Q12->SetMarkerStyle(standard_marker_style);
	Q12->SetMarkerSize(standard_marker_size);
	TF1 *Q12_algebra_based_fit = new TF1("Q12_algebra_based_fit","[0]*x+[1]",xlow,xhigh);
	Q12->Fit("Q12_algebra_based_fit","0");
	Q12->Draw("P same");
	Q12_algebra_based_fit->SetLineColor(kBlack);
	Q12_algebra_based_fit->SetLineWidth(standard_line_width);
	Q12_algebra_based_fit->Draw("same");
	p14->Print("Q20_algebra_based.pdf");

	// //=====Question 19 versus semester for PHYS150/180.  m = number of times taught.=====//
	Float_t x12[m2];
	Float_t y12[m2];
	Float_t ex12[m2];
	Float_t ey12[m2];
	c2 = 0;

	for(Int_t i=0;i<n;++i)
	{
		eval_data->GetEntry(i);
		string thisCourse(course);
		if((thisCourse=="150" || thisCourse=="180") && question==20)
		{
			x12[c2] = (Float_t)c2+1.0;
			ex12[c2] = 0.0;
			y12[c2] = mean;
			ey12[c2] = sd/sqrt(N)+0.01;
			++c2;
		}
	}

	TCanvas* Q12_calculus_based = new TCanvas("Q19_calculus_based","Q19_calculus_based",1200,1200);
	TPad* p15 = new TPad("p15","p15",0.0,0.0,1.0,1.0);
	p15->Draw();
	p15->SetLeftMargin(lmargin);
	p15->SetRightMargin(rmargin);
	p15->SetTopMargin(tmargin);
	p15->SetBottomMargin(bmargin);
	p15->SetGridx();
	p15->SetGridy();
	p15->SetTickx();
	p15->SetTicky();
	p15->cd();
	h_mark->Draw();

	TGraphErrors *Q12_2 = new TGraphErrors(m2,x12,y12,ex12,ey12);
	Q12_2->SetMarkerStyle(standard_marker_style);
	Q12_2->SetMarkerSize(standard_marker_size);
	TF1 *Q12_calculus_based_fit = new TF1("Q12_calculus_based_fit","[0]*x+[1]",xlow,xhigh);
	Q12_2->Fit("Q12_calculus_based_fit","0");
	Q12_2->Draw("P same");
	Q12_calculus_based_fit->SetLineColor(kBlack);
	Q12_calculus_based_fit->SetLineWidth(standard_line_width);
	Q12_calculus_based_fit->Draw("same");
	p15->Print("Q20_calculus_based.pdf");


	// //=====Question 17 vs. 16 for PHYS135A/B.  m = number of times taught.=====//
	// TCanvas* Q16_Q17_algebra_based = new TCanvas("Q16_Q17_algebra_based","Q16_Q17_algebra_based",1200,1200);
	// TPad* p7 = new TPad("p7","p7",0.0,0.0,1.0,1.0);
	// p7->Draw();
	// p7->SetLeftMargin(lmargin);
	// p7->SetRightMargin(rmargin);
	// p7->SetTopMargin(tmargin);
	// p7->SetBottomMargin(bmargin);
	// p7->SetGridx();
	// p7->SetGridy();
	// p7->SetTickx();
	// p7->SetTicky();
	// p7->cd();
	// h_mark->GetYaxis()->SetTitle("Q16: Mean #pm Error in Mean");
	// h_mark->GetXaxis()->SetTitle("Q17: Mean #pm Error in Mean");
	// h_mark->GetXaxis()->SetRangeUser(xlow,xhigh);
	// h_mark->GetYaxis()->SetRangeUser(ylow,yhigh);
	// h_mark->Draw();

	// TGraphErrors *Q16_17 = new TGraphErrors(m,y5,y3,ey5,ey3);
	// Q16_17->SetMarkerStyle(standard_marker_style);
	// Q16_17->SetMarkerSize(standard_marker_size);
	// Q16_17->Draw("P same");
	// string corr_result = Form("Correlation coefficient: %1.3f",Q16_17->GetCorrelationFactor());
	// TText *pt = new TText(0.5,4.5,corr_result.c_str());
	// pt->SetTextFont(fontCode);
	// pt->SetTextSize(tsize*0.8);
	// pt->Draw("same");
	// p7->Print("Q16_Q17_algebra_based.pdf");

	// //=====Question 17 vs. 16 for PHYS150/180.  m = number of times taught.=====//
	// TCanvas* Q16_Q17_calculus_based = new TCanvas("Q16_Q17_calculus_based","Q16_Q17_calculus_based",1200,1200);
	// TPad* p8 = new TPad("p8","p8",0.0,0.0,1.0,1.0);
	// p8->Draw();
	// p8->SetLeftMargin(lmargin);
	// p8->SetRightMargin(rmargin);
	// p8->SetTopMargin(tmargin);
	// p8->SetBottomMargin(bmargin);
	// p8->SetGridx();
	// p8->SetGridy();
	// p8->SetTickx();
	// p8->SetTicky();
	// p8->cd();
	// h_mark->Draw();

	// TGraphErrors *Q16_17_2 = new TGraphErrors(m2,y6,y4,ey6,ey4);
	// Q16_17_2->SetMarkerStyle(standard_marker_style);
	// Q16_17_2->SetMarkerSize(standard_marker_size);
	// Q16_17_2->Draw("P same");
	// corr_result = Form("Correlation coefficient: %1.3f",Q16_17_2->GetCorrelationFactor());
	// TText *pt2 = new TText(0.5,4.5,corr_result.c_str());
	// pt2->SetTextFont(fontCode);
	// pt2->SetTextSize(tsize*0.8);
	// pt2->Draw("same");
	// p8->Print("Q16_Q17_calculus_based.pdf");

	// delete p1,p2,p3,p4,p5,p6,p7,p8;
	// delete Q16_algebra_based,Q16_calculus_based;
	// delete Q17_algebra_based,Q17_calculus_based;
	// delete Q25_algebra_based,Q25_calculus_based;
	// delete Q16_calculus_based_fit,Q16_algebra_based_fit;
	// delete Q17_calculus_based_fit,Q17_algebra_based_fit;
	// delete Q25_calculus_based_fit,Q25_algebra_based_fit;
	// delete Q16,Q17,Q16_2,Q17_2,Q25,Q25_2,Q16_17,Q16_17_2;
	// delete pt,pt2;

	// =====All questions, all classes vs. semester number=====//
	// const Int_t q = 8; //number of lower-division courses I've taught
	// const Int_t q2 = 4; //number of upper-division courses I've taught
	const Int_t p = 16; //number of questions considered
	// Int_t counter = 0;
	// Int_t counter2 = 0;
	// Float_t qoff = 10.0;
	// Float_t dx = 0.06;
	// TGraphErrors *allQ_lowerDiv = new TGraphErrors(q*p-1);
	// allQ_lowerDiv->SetMarkerStyle(32);
	// allQ_lowerDiv->SetMarkerSize(standard_marker_size*1.2);
	// TGraphErrors *allQ_upperDiv = new TGraphErrors(q2*p);
	// allQ_upperDiv->SetMarkerStyle(26);
	// allQ_upperDiv->SetMarkerSize(standard_marker_size*1.2);

	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisYear(year);
	// 	string thisSemester(semester);
	// 	string thisCourse(course);
	// 	Float_t x = 0.0;
	// 	if(thisYear=="2017" && thisSemester=="Fall")
	// 	{
	// 		x = 1.0+(question-qoff)*dx;
	// 	}
	// 	else if(thisYear=="2018" && thisSemester=="Spring")
	// 	{
	// 		x = 2.0+(question-qoff)*dx;
	// 	}
	// 	else if(thisYear=="2018" && thisSemester=="Fall")
	// 	{
	// 		x = 3.0+(question-qoff)*dx;
	// 	}
	// 	else if(thisYear=="2019" && thisSemester=="Jan")
	// 	{
	// 		x = 4.0+(question-qoff)*dx;
	// 	}
	// 	else if(thisYear=="2019" && thisSemester=="Spring")
	// 	{
	// 		x = 5.0+(question-qoff)*dx;
	// 	}
	// 	else
	// 	{
	// 		x = 6.0;
	// 	}
	// 	if(question>=10 && question<=25)
	// 	{
	// 		if(mean>2.28) //Nope lol
	// 		{
	// 			if(thisCourse=="135A" || thisCourse=="135B" || thisCourse=="150" || thisCourse=="180")
	// 			{
	// 				allQ_lowerDiv->SetPoint(counter,x,mean);
	// 				allQ_lowerDiv->SetPointError(counter,0.0,sd/sqrt(N));
	// 				++counter;
	// 			}
	// 			else
	// 			{
	// 				allQ_upperDiv->SetPoint(counter2,x,mean);
	// 				allQ_upperDiv->SetPointError(counter2,0.0,sd/sqrt(N));
	// 				++counter2;
	// 			}
	// 		}
	// 	}
	// }
	// TCanvas* Q = new TCanvas("Q","Q",1200,1200);
	// TPad* p9 = new TPad("p9","p9",0.0,0.0,1.0,1.0);
	// p9->Draw();
	// p9->SetLeftMargin(lmargin);
	// p9->SetRightMargin(rmargin);
	// p9->SetTopMargin(tmargin);
	// p9->SetBottomMargin(bmargin);
	// p9->SetGridx();
	// p9->SetGridy();
	// p9->SetTickx();
	// p9->SetTicky();
	// p9->cd();
	// h_mark->GetXaxis()->SetTitle("Time (semesters taught)");
	// h_mark->GetYaxis()->SetTitle("Q10-Q25: Mean #pm Error in Mean");
	// h_mark->GetXaxis()->SetRangeUser(xlow+1,xhigh+1);
	// h_mark->Draw();
	// allQ_upperDiv->Draw("P same");
	// allQ_lowerDiv->Draw("P same");

	// TLegend *Qleg = new TLegend(0.5,0.2,0.85,0.4);
	// Qleg->SetTextFont(fontCode);
	// Qleg->SetTextSize(tsize*0.8);
	// Qleg->AddEntry(allQ_lowerDiv,"Lower Division","p");
	// Qleg->AddEntry(allQ_upperDiv,"Upper Division","p");
	// Qleg->Draw("same");
	// p9->Print("Q10_Q25_all_courses_vs_time.pdf");

	// delete p9;
	// delete Q;
	// delete Qleg;
	// delete allQ_lowerDiv;
	// delete allQ_upperDiv;

	// Create LaTeX table content, for algebra-based and calculus-based
	// Float_t algebra_based_q_first[p];
	// Float_t algebra_based_q_first_err[p];
	// Float_t algebra_based_q_last[p];
	// Float_t algebra_based_q_last_err[p];
	// Float_t calculus_based_q_first[p];
	// Float_t calculus_based_q_first_err[p];
	// Float_t calculus_based_q_last[p];
	// Float_t calculus_based_q_last_err[p];
	// for(Int_t i=0;i<n;++i)
	// {
	// 	eval_data->GetEntry(i);
	// 	string thisCourse(course);
	// 	string thisSemester(semester);
	// 	string thisYear(year);
	// 	if(thisCourse=="135A" && thisSemester=="Fall" && thisYear=="2017" && question>=10)
	// 	{
	// 		algebra_based_q_first[question-10] = mean;
	// 		algebra_based_q_first_err[question-10] = sd/sqrt(N);
	// 	}
	// 	if(thisCourse=="135B" && thisSemester=="Spring" && thisYear=="2019" && question>=10)
	// 	{
	// 		algebra_based_q_last[question-10] = mean;
	// 		algebra_based_q_last_err[question-10] = sd/sqrt(N);
	// 	}
	// 	if(thisCourse=="150" && thisSemester=="Fall" && thisYear=="2017" && question>=10)
	// 	{
	// 		calculus_based_q_first[question-10] = mean;
	// 		calculus_based_q_first_err[question-10] = sd/sqrt(N);
	// 	}
	// 	if(thisCourse=="180" && thisSemester=="Spring" && thisYear=="2019" && question>=10)
	// 	{
	// 		calculus_based_q_last[question-10] = mean;
	// 		calculus_based_q_last_err[question-10] = sd/sqrt(N);
	// 	}
	// }
	// std::cout.precision(3);
	// std::cout<<"\\begin{table}"<<std::endl;
	// std::cout<<"\\small"<<std::endl;
	// std::cout<<"\\centering"<<std::endl;
	// std::cout<<"\\begin{tabular}{| c | c | c | c | c |}"<<std::endl;
	// std::cout<<"\\hline"<<std::endl;
	// std::cout<<"\\hline"<<std::endl;
	// std::cout<<"Question & First Time & Most Recent Time & Raw change & Standard deviations \\\\"<<std::endl;
	// std::cout<<"\\hline"<<std::endl;
	// for(Int_t z=0;z<p;++z)
	// {
	// 	std::cout<<z+10<<" & ";
	// 	std::cout<<algebra_based_q_first[z]<<" $\\pm$ "<<algebra_based_q_first_err[z];
	// 	std::cout<<" & ";
	// 	std::cout<<algebra_based_q_last[z]<<" $\\pm$ "<<algebra_based_q_last_err[z];
	// 	std::cout<<" & ";
	// 	Float_t delta = algebra_based_q_last[z]-algebra_based_q_first[z];
	// 	Float_t sigma = sqrt((algebra_based_q_last_err[z])*(algebra_based_q_last_err[z])
	// 		+(algebra_based_q_first_err[z])*(algebra_based_q_first_err[z]));
	// 	std::cout<<delta<<" $\\pm$ "<<sigma<<" & "<<delta/sigma;
	// 	std::cout<<" \\\\";
	// 	std::cout<<" \\hline"<<std::endl;
	// }
	// std::cout<<"\\hline"<<std::endl;
	// std::cout<<"\\end{tabular}"<<std::endl;
	// std::cout<<"\\caption{\\label{tab:courses:intro_shifts} Comparison algebra-based numbers for the first time taught (first column) to the most recent time (second column). The raw change is given in the third column, and the change divided by the standard deviation is given in the fourth column.}"<<std::endl;
	// std::cout<<"\\end{table}"<<std::endl;
	// std::cout<<std::endl;
	// std::cout<<"\\begin{table}"<<std::endl;
	// std::cout<<"\\small"<<std::endl;
	// std::cout<<"\\centering"<<std::endl;
	// std::cout<<"\\begin{tabular}{| c | c | c | c | c |}"<<std::endl;
	// std::cout<<"\\hline"<<std::endl;
	// std::cout<<"\\hline"<<std::endl;
	// std::cout<<"Question & First Time & Most Recent Time & Raw change & Standard deviations \\\\"<<std::endl;
	// std::cout<<"\\hline"<<std::endl;
	// for(Int_t z=0;z<p;++z)
	// {
	// 	std::cout<<z+10<<" & ";
	// 	std::cout<<calculus_based_q_first[z]<<" $\\pm$ "<<calculus_based_q_first_err[z];
	// 	std::cout<<" & ";
	// 	std::cout<<calculus_based_q_last[z]<<" $\\pm$ "<<calculus_based_q_last_err[z];
	// 	std::cout<<" & ";
	// 	Float_t delta = calculus_based_q_last[z]-calculus_based_q_first[z];
	// 	Float_t sigma = sqrt((calculus_based_q_last_err[z])*(calculus_based_q_last_err[z])
	// 		+(calculus_based_q_first_err[z])*(calculus_based_q_first_err[z]));
	// 	std::cout<<delta<<" $\\pm$ "<<sigma<<" & "<<delta/sigma;
	// 	std::cout<<" \\\\";
	// 	std::cout<<" \\hline"<<std::endl;
	// }
	// std::cout<<"\\hline"<<std::endl;
	// std::cout<<"\\end{tabular}"<<std::endl;
	// std::cout<<"\\caption{\\label{tab:courses:intro_shifts_2} Comparison calculus-based numbers for the first time taught (first column) to the most recent time (second column). The raw change is given in the third column, and the change divided by the standard deviation is given in the fourth column.}"<<std::endl;
	// std::cout<<"\\end{table}"<<std::endl;

	// Compare COSC330 w/ COSC390.
	Float_t adv_q_first[p];
	Float_t adv_q_first_err[p];
	Float_t adv_q_last[p];
	Float_t adv_q_last_err[p];
	for(Int_t i=0;i<n;++i)
	{
		eval_data->GetEntry(i);
		string thisCourse(course);
		if(thisCourse=="PHYS306_COSC330" && question>=10)
		{
			adv_q_first[question-10] = mean;
			adv_q_first_err[question-10] = sd/sqrt(N);
		}
		if(thisCourse=="COSC390" && question>=10)
		{
			adv_q_last[question-10] = mean;
			adv_q_last_err[question-10] = sd/sqrt(N);
		}
	}
	std::cout.precision(3);
	std::cout<<"\\begin{table}"<<std::endl;
	std::cout<<"\\small"<<std::endl;
	std::cout<<"\\centering"<<std::endl;
	std::cout<<"\\begin{tabular}{| c | c | c | c | c |}"<<std::endl;
	std::cout<<"\\hline"<<std::endl;
	std::cout<<"\\hline"<<std::endl;
	std::cout<<"Question & First Time & Most Recent Time & Raw change & Standard deviations \\\\"<<std::endl;
	std::cout<<"\\hline"<<std::endl;
	for(Int_t z=0;z<p;++z)
	{
		std::cout<<z+10<<" & ";
		std::cout<<adv_q_first[z]<<" $\\pm$ "<<adv_q_first_err[z];
		std::cout<<" & ";
		std::cout<<adv_q_last[z]<<" $\\pm$ "<<adv_q_last_err[z];
		std::cout<<" & ";
		Float_t delta = adv_q_last[z]-adv_q_first[z];
		Float_t sigma = sqrt((adv_q_last_err[z])*(adv_q_last_err[z])
			+(adv_q_first_err[z])*(adv_q_first_err[z]));
		std::cout<<delta<<" $\\pm$ "<<sigma<<" & "<<delta/sigma;
		std::cout<<" \\\\";
		std::cout<<" \\hline"<<std::endl;
	}
	std::cout<<"\\hline"<<std::endl;
	std::cout<<"\\end{tabular}"<<std::endl;
	std::cout<<"\\caption{\\label{tab:courses:adv_shifts} Comparison of advanced course numbers for the first time taught (first column) to the most recent time (second column). The raw change is given in the third column, and the change divided by the standard deviation is given in the fourth column.}"<<std::endl;
	std::cout<<"\\end{table}"<<std::endl;
	std::cout<<std::endl;
}