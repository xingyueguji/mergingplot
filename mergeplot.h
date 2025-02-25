//
// Global variables
//

/* Naming:
HI_pp_dM_chi2_eta_nominal->Write("HI_pp_dM_chi2_eta_nominal", 2);
HI_pp_dM_chi2_eta_tnpU->Write("HI_pp_dM_chi2_eta_tnpU", 2);
HI_pp_dM_chi2_eta_tnpD->Write("HI_pp_dM_chi2_eta_tnpD", 2);
HI_pp_dM_chi2_eta_acooff->Write("HI_pp_dM_chi2_eta_acooff", 2);
HI_pp_dM_chi2_eta_nominal_no_bk->Write("HI_pp_dM_chi2_eta_nominal_no_bk", 2);
HI_pp_dM_chi2_eta_nominal_uniform_rebin->Write("HI_pp_dM_chi2_eta_nominal_uniform_rebin", 2);
HI_pp_dM_chi2_eta_nominal_mass_range->Write("HI_pp_dM_chi2_eta_nominal_mass_range", 2);
*/

TGraphErrors *g_zh_HI_dM_nominal;
TGraphErrors *g_zh_HI_dW_nominal;
TGraphErrors *g_zh_HI_dM_tnpU;
TGraphErrors *g_zh_HI_dW_tnpU;
TGraphErrors *g_zh_HI_dM_tnpD;
TGraphErrors *g_zh_HI_dW_tnpD;
TGraphErrors *g_zh_HI_dM_acooff;
TGraphErrors *g_zh_HI_dW_acooff;
TGraphErrors *g_zh_HI_dM_nominal_no_bk;
TGraphErrors *g_zh_HI_dW_nominal_no_bk;
TGraphErrors *g_zh_HI_dM_nominal_uniform_rebin;
TGraphErrors *g_zh_HI_dW_nominal_uniform_rebin;
TGraphErrors *g_zh_HI_dM_nominal_mass_range;
TGraphErrors *g_zh_HI_dW_nominal_mass_range;
TGraphErrors *g_zh_HI_dM_HF_up;
TGraphErrors *g_zh_HI_dW_HF_up;
TGraphErrors *g_zh_HI_dM_HF_down;
TGraphErrors *g_zh_HI_dW_HF_down;

TGraphErrors *g_zh_HI_dM_nominal_minuspp;
TGraphErrors *g_zh_HI_dW_nominal_minuspp;
TGraphErrors *g_zh_HI_dM_tnpU_minuspp;
TGraphErrors *g_zh_HI_dW_tnpU_minuspp;
TGraphErrors *g_zh_HI_dM_tnpD_minuspp;
TGraphErrors *g_zh_HI_dW_tnpD_minuspp;
TGraphErrors *g_zh_HI_dM_acooff_minuspp;
TGraphErrors *g_zh_HI_dW_acooff_minuspp;
TGraphErrors *g_zh_HI_dM_nominal_no_bk_minuspp;
TGraphErrors *g_zh_HI_dW_nominal_no_bk_minuspp;
TGraphErrors *g_zh_HI_dM_nominal_uniform_rebin_minuspp;
TGraphErrors *g_zh_HI_dW_nominal_uniform_rebin_minuspp;
TGraphErrors *g_zh_HI_dM_nominal_mass_range_minuspp;
TGraphErrors *g_zh_HI_dW_nominal_mass_range_minuspp;
TGraphErrors *g_zh_HI_dM_HF_down_minuspp;
TGraphErrors *g_zh_HI_dW_HF_down_minuspp;
TGraphErrors *g_zh_HI_dM_HF_up_minuspp;
TGraphErrors *g_zh_HI_dW_HF_up_minuspp;

// Frank's fit

TGraphErrors *g_frank_fit_dM_nominal;
TGraphErrors *g_frank_fit_dM_changesig;
TGraphErrors *g_frank_fit_dM_linearbackground;
TGraphErrors *g_frank_fit_dM_CB;

TGraphErrors *g_frank_fit_dW_nominal;
TGraphErrors *g_frank_fit_dW_changesig;
TGraphErrors *g_frank_fit_dW_linearbackground;
TGraphErrors *g_frank_fit_dW_CB;

TGraphErrors *g_frank_fit_dM_nominal_minuspp;
TGraphErrors *g_frank_fit_dM_changesig_minuspp;
TGraphErrors *g_frank_fit_dM_linearbackground_minuspp;
TGraphErrors *g_frank_fit_dM_CB_minuspp;

TGraphErrors *g_frank_fit_dW_nominal_minuspp;
TGraphErrors *g_frank_fit_dW_changesig_minuspp;
TGraphErrors *g_frank_fit_dW_linearbackground_minuspp;
TGraphErrors *g_frank_fit_dW_CB_minuspp;

TH1D *h_frank_fit_pp_dM_nominal;
TH1D *h_frank_fit_pp_dM_changesig;
TH1D *h_frank_fit_pp_dM_linearbackground;
TH1D *h_frank_fit_pp_dM_CB;

TH1D *h_frank_fit_pp_dW_nominal;
TH1D *h_frank_fit_pp_dW_changesig;
TH1D *h_frank_fit_pp_dW_linearbackground;
TH1D *h_frank_fit_pp_dW_CB;

// Frank's RMS

TGraphErrors *g_frank_rms_dM_nominal;
TGraphErrors *g_frank_rms_dW_nominal;

TGraphErrors *g_frank_rms_dM_nominal_minuspp;
TGraphErrors *g_frank_rms_dW_nominal_minuspp;

TH1D *g_frank_rms_pp_dM_nominal;
TH1D *g_frank_rms_pp_dW_nominal;

TGraphErrors *g_frank_rms_pesudo_dM_3gamma;
TGraphErrors *g_frank_rms_pesudo_dM_4gamma;
TGraphErrors *g_frank_rms_pesudo_dM_5gamma;

TGraphErrors *g_frank_rms_pesudo_dM_3gamma_minuspp;
TGraphErrors *g_frank_rms_pesudo_dM_4gamma_minuspp;
TGraphErrors *g_frank_rms_pesudo_dM_5gamma_minuspp;

TGraphErrors *g_frank_rms_pesudo_dW_3gamma;
TGraphErrors *g_frank_rms_pesudo_dW_4gamma;
TGraphErrors *g_frank_rms_pesudo_dW_5gamma;

TGraphErrors *g_frank_rms_pesudo_dW_3gamma_minuspp;
TGraphErrors *g_frank_rms_pesudo_dW_4gamma_minuspp;
TGraphErrors *g_frank_rms_pesudo_dW_5gamma_minuspp;