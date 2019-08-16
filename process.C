void process()
{
	TFile *output_file = new TFile("eval_data.root","RECREATE");
	TTree *eval_data = new TTree("eval_data","eval_data");
	eval_data->ReadFile("EvalData.csv","question/i:N/i:mean/F:sd/F:w1/i:w2/i:w3/i:w4/i:w5/i:course/C:year/C:semester/C",',');
	eval_data->Write();
	output_file->Close();
}
