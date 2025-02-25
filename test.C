#include "mergeplot.h"

void readfrankplotrms(TFile *f1, TFile *f2, bool iseta)
{
    TDirectoryFile *dir_graph;
    TDirectoryFile *dir_canvas;

    TCanvas *c_frank_rms_dM;
    TCanvas *c_frank_rms_dW;

    if (!iseta)
    {
        dir_graph = (TDirectoryFile *)f1->GetDirectory("GraphsValues/WholeAcceptance");
        dir_canvas = (TDirectoryFile *)f1->GetDirectory("Canvases/Values/WholeAcceptance");
        g_frank_rms_dM_nominal = (TGraphErrors *)dir_graph->Get("massValGraph_WA");
        g_frank_rms_dW_nominal = (TGraphErrors *)dir_graph->Get("widthValGraph_WA");

        c_frank_rms_dM = (TCanvas *)dir_canvas->Get("cMassVal_WA_NewCent");
        c_frank_rms_dW = (TCanvas *)dir_canvas->Get("cWidthVal_WA_NewCent");

        g_frank_rms_pp_dM_nominal = (TH1D *)c_frank_rms_dM->GetListOfPrimitives()->FindObject("HistMassValpp_WA_NewCent_dummyHist");
        g_frank_rms_pp_dW_nominal = (TH1D *)c_frank_rms_dW->GetListOfPrimitives()->FindObject("HistWidthValpp_WA_NewCent_dummyHist");
    }

    if (iseta)
    {
        dir_graph = (TDirectoryFile *)f1->GetDirectory("GraphsValues/Barrel");
        dir_canvas = (TDirectoryFile *)f1->GetDirectory("Canvases/Values/Barrel");
        g_frank_rms_dM_nominal = (TGraphErrors *)dir_graph->Get("massValGraph_barrel");
        g_frank_rms_dW_nominal = (TGraphErrors *)dir_graph->Get("widthValGraph_barrel");

        c_frank_rms_dM = (TCanvas *)dir_canvas->Get("cMassVal_barrel_NewCent");
        c_frank_rms_dW = (TCanvas *)dir_canvas->Get("cWidthVal_barrel_NewCent");

        g_frank_rms_pp_dM_nominal = (TH1D *)c_frank_rms_dM->GetListOfPrimitives()->FindObject("HistMassValpp_barrel_NewCent_dummyHist");
        g_frank_rms_pp_dW_nominal = (TH1D *)c_frank_rms_dW->GetListOfPrimitives()->FindObject("HistWidthValpp_barrel_NewCent_dummyHist");
    }
}

void test()
{
    TFile *f1 = new TFile("./RMS/ppPbPbCentMeanRMS_bkgd_subtracted.root", "READ");
    readfrankplotrms(f1, f1, 1);
}