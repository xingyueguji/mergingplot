//
// Global variables
//

// Naming:
// pp_dM_chi2_eta_bksub
// pp_dWidth_chi2_eta_bksub
// pp_dM_chi2_eta_nobksub
// pp_dWidth_chi2_eta_nobksub
// pp_dM_chi2_raw_bksub
// pp_dWidth_chi2_raw_bksub
// pp_dM_chi2_raw_nobksub
// pp_dWidth_chi2_raw_nobksub
// HI_dM_chi2_eta_bksub
// HI_dWidth_chi2_eta_bksub
// HI_dM_chi2_eta
// HI_dWidth_chi2_eta
// HI_dM_chi2_raw_bksub
// HI_dWidth_chi2_raw_bksub
// HI_dM_chi2_raw
// HI_dWidth_chi2_raw

TGraphErrors *g_zh_HI_dM;
TGraphErrors *g_zh_HI_dW;
TGraphErrors *g_zh_HI_dM_new;
TGraphErrors *g_zh_HI_dW_new;
TGraphErrors *g_zh_pp_dM;
TGraphErrors *g_zh_pp_dW;

TGraphErrors *g_frank_rms_dM;
TGraphErrors *g_frank_rms_dW;
TGraphErrors *g_frank_fit_dM;
TGraphErrors *g_frank_fit_dW;

TH1D *h_frank_fit_pp_dM;
TH1D *h_frank_fit_pp_dW;

TCanvas *c_frank_fit_dM;
TCanvas *c_frank_fit_dW;


double fit_dm;
double fit_dm_err;

double fit_dw;
double fit_dw_err;
