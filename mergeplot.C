#include "mergeplot.h"
#include "CMS_lumi.C"
#include "tdrStyle.C"

void readfrankplot(TFile *f1, int type)
{

    TCanvas *c_frank_fit_dM;
    TCanvas *c_frank_fit_dW;

    f1->cd();
    TDirectoryFile *dir_graph;
    TDirectoryFile *dir_canvas;

    dir_graph = (TDirectoryFile *)f1->GetDirectory("GraphsValues");
    dir_canvas = (TDirectoryFile *)f1->GetDirectory("Canvases");
    c_frank_fit_dM = (TCanvas *)dir_canvas->Get("cMassValNewCent");
    c_frank_fit_dW = (TCanvas *)dir_canvas->Get("cWidthValNewCent");

    if (type == 1)
    {
        g_frank_fit_dM_nominal = (TGraphErrors *)dir_graph->Get("massValGraphNewCent");
        g_frank_fit_dW_nominal = (TGraphErrors *)dir_graph->Get("widthValGraphNewCent");
        h_frank_fit_pp_dM_nominal = (TH1D *)c_frank_fit_dM->GetListOfPrimitives()->FindObject("HistMassValppNewCent_dummyHist");
        h_frank_fit_pp_dW_nominal = (TH1D *)c_frank_fit_dW->GetListOfPrimitives()->FindObject("HistWidthValppNewCent_dummyHist");
    }
    if (type == 2)
    {
        g_frank_fit_dM_changesig = (TGraphErrors *)dir_graph->Get("massValGraphNewCent");
        g_frank_fit_dW_changesig = (TGraphErrors *)dir_graph->Get("widthValGraphNewCent");
        h_frank_fit_pp_dM_changesig = (TH1D *)c_frank_fit_dM->GetListOfPrimitives()->FindObject("HistMassValppNewCent_dummyHist");
        h_frank_fit_pp_dW_changesig = (TH1D *)c_frank_fit_dW->GetListOfPrimitives()->FindObject("HistWidthValppNewCent_dummyHist");
    }
    if (type == 3)
    {
        g_frank_fit_dM_linearbackground = (TGraphErrors *)dir_graph->Get("massValGraphNewCent");
        g_frank_fit_dW_linearbackground = (TGraphErrors *)dir_graph->Get("widthValGraphNewCent");
        h_frank_fit_pp_dM_linearbackground = (TH1D *)c_frank_fit_dM->GetListOfPrimitives()->FindObject("HistMassValppNewCent_dummyHist");
        h_frank_fit_pp_dW_linearbackground = (TH1D *)c_frank_fit_dW->GetListOfPrimitives()->FindObject("HistWidthValppNewCent_dummyHist");
    }
    if (type == 4)
    {
        g_frank_fit_dM_CB = (TGraphErrors *)dir_graph->Get("massValGraphNewCent");
        g_frank_fit_dW_CB = (TGraphErrors *)dir_graph->Get("widthValGraphNewCent");
        h_frank_fit_pp_dM_CB = (TH1D *)c_frank_fit_dM->GetListOfPrimitives()->FindObject("HistMassValppNewCent_dummyHist");
        h_frank_fit_pp_dW_CB = (TH1D *)c_frank_fit_dW->GetListOfPrimitives()->FindObject("HistWidthValppNewCent_dummyHist");
    }
}
void readfrankplotrms(TFile *f1, TFile *f2, bool iseta)
{
    TDirectoryFile *dir_graph;
    TDirectoryFile *dir_canvas;

    TDirectoryFile *dir_systematic_Mass;
    TDirectoryFile *dir_systematic_RMS;

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

        dir_systematic_Mass = (TDirectoryFile *)f2->GetDirectory("Graphs/Vals/Mass");
        dir_systematic_RMS = (TDirectoryFile *)f2->GetDirectory("Graphs/Vals/RMS");

        g_frank_rms_pesudo_dM_3gamma = (TGraphErrors *)dir_systematic_Mass->Get("Graph;1");
        g_frank_rms_pesudo_dM_4gamma = (TGraphErrors *)dir_systematic_Mass->Get("Graph;2");
        g_frank_rms_pesudo_dM_5gamma = (TGraphErrors *)dir_systematic_Mass->Get("Graph;3");

        g_frank_rms_pesudo_dW_3gamma = (TGraphErrors *)dir_systematic_RMS->Get("Graph;1");
        g_frank_rms_pesudo_dW_4gamma = (TGraphErrors *)dir_systematic_RMS->Get("Graph;2");
        g_frank_rms_pesudo_dW_5gamma = (TGraphErrors *)dir_systematic_RMS->Get("Graph;3");
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
void readplot(TFile *f1, bool iseta)
{
    f1->cd();

    if (iseta)
    {
        g_zh_HI_dM_nominal = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_nominal");
        g_zh_HI_dW_nominal = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_nominal");
        g_zh_HI_dM_tnpU = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_tnpU");
        g_zh_HI_dW_tnpU = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_tnpU");
        g_zh_HI_dM_tnpD = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_tnpD");
        g_zh_HI_dW_tnpD = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_tnpD");
        g_zh_HI_dM_acooff = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_acooff");
        g_zh_HI_dW_acooff = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_acooff");
        g_zh_HI_dM_nominal_no_bk = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_nominal_no_bk");
        g_zh_HI_dW_nominal_no_bk = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_nominal_no_bk");
        g_zh_HI_dM_nominal_uniform_rebin = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_nominal_uniform_rebin");
        g_zh_HI_dW_nominal_uniform_rebin = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_nominal_uniform_rebin");
        g_zh_HI_dM_nominal_mass_range = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_nominal_mass_range");
        g_zh_HI_dW_nominal_mass_range = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_nominal_mass_range");
        g_zh_HI_dM_HF_up = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_HF_up");
        g_zh_HI_dW_HF_up = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_HF_up");
        g_zh_HI_dM_HF_down = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_eta_HF_down");
        g_zh_HI_dW_HF_down = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_eta_HF_down");

        g_zh_HI_dM_nominal_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_nominal");
        g_zh_HI_dW_nominal_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_nominal");
        g_zh_HI_dM_tnpU_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_tnpU");
        g_zh_HI_dW_tnpU_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_tnpU");
        g_zh_HI_dM_tnpD_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_tnpD");
        g_zh_HI_dW_tnpD_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_tnpD");
        g_zh_HI_dM_acooff_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_acooff");
        g_zh_HI_dW_acooff_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_acooff");
        g_zh_HI_dM_nominal_no_bk_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_nominal_no_bk");
        g_zh_HI_dW_nominal_no_bk_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_nominal_no_bk");
        g_zh_HI_dM_nominal_uniform_rebin_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_nominal_uniform_rebin");
        g_zh_HI_dW_nominal_uniform_rebin_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_nominal_uniform_rebin");
        g_zh_HI_dM_nominal_mass_range_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_nominal_mass_range");
        g_zh_HI_dW_nominal_mass_range_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_nominal_mass_range");
        g_zh_HI_dM_HF_up_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_HF_up");
        g_zh_HI_dW_HF_up_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_HF_up");
        g_zh_HI_dM_HF_down_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_eta_HF_down");
        g_zh_HI_dW_HF_down_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_eta_HF_down");
    }
    else
    {

        g_zh_HI_dM_nominal = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_nominal");
        g_zh_HI_dW_nominal = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_nominal");
        g_zh_HI_dM_tnpU = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_tnpU");
        g_zh_HI_dW_tnpU = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_tnpU");
        g_zh_HI_dM_tnpD = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_tnpD");
        g_zh_HI_dW_tnpD = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_tnpD");
        g_zh_HI_dM_acooff = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_acooff");
        g_zh_HI_dW_acooff = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_acooff");
        g_zh_HI_dM_nominal_no_bk = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_nominal_no_bk");
        g_zh_HI_dW_nominal_no_bk = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_nominal_no_bk");
        g_zh_HI_dM_nominal_uniform_rebin = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_nominal_uniform_rebin");
        g_zh_HI_dW_nominal_uniform_rebin = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_nominal_uniform_rebin");
        g_zh_HI_dM_nominal_mass_range = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_nominal_mass_range");
        g_zh_HI_dW_nominal_mass_range = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_nominal_mass_range");
        g_zh_HI_dM_HF_up = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_HF_up");
        g_zh_HI_dW_HF_up = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_HF_up");
        g_zh_HI_dM_HF_down = (TGraphErrors *)f1->Get("HI_pp_dM_chi2_raw_HF_down");
        g_zh_HI_dW_HF_down = (TGraphErrors *)f1->Get("HI_pp_dWidth_chi2_raw_HF_down");

        g_zh_HI_dM_nominal_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_nominal");
        g_zh_HI_dW_nominal_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_nominal");
        g_zh_HI_dM_tnpU_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_tnpU");
        g_zh_HI_dW_tnpU_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_tnpU");
        g_zh_HI_dM_tnpD_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_tnpD");
        g_zh_HI_dW_tnpD_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_tnpD");
        g_zh_HI_dM_acooff_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_acooff");
        g_zh_HI_dW_acooff_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_acooff");
        g_zh_HI_dM_nominal_no_bk_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_nominal_no_bk");
        g_zh_HI_dW_nominal_no_bk_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_nominal_no_bk");
        g_zh_HI_dM_nominal_uniform_rebin_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_nominal_uniform_rebin");
        g_zh_HI_dW_nominal_uniform_rebin_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_nominal_uniform_rebin");
        g_zh_HI_dM_nominal_mass_range_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_nominal_mass_range");
        g_zh_HI_dW_nominal_mass_range_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_nominal_mass_range");
        g_zh_HI_dM_HF_up_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_HF_up");
        g_zh_HI_dW_HF_up_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_HF_up");
        g_zh_HI_dM_HF_down_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dM_chi2_raw_HF_down");
        g_zh_HI_dW_HF_down_minuspp = (TGraphErrors *)f1->Get("HI_sub_pp_dWidth_chi2_raw_HF_down");
    }
}

void changeorderand(TGraphErrors *g1)
{
    int n = g1->GetN();

    if (n < 6) // Need at least 6 points to perform this swap
    {
        std::cerr << "Graph must have at least six points to rearrange in the desired order." << std::endl;
        return;
    }

    // Temporary arrays for the rearranged points
    double *x = new double[n];
    double *y = new double[n];
    double *ex = new double[n];
    double *ey = new double[n];

    // Extract current points
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
    }

    // Store the first point (x1, y1)
    double firstX = x[0], firstY = y[0], firstEX = ex[0], firstEY = ey[0];

    // Shift points 2,3,4,5 one place left
    for (int i = 1; i <= 4; ++i)
    {
        y[i - 1] = y[i];
        ey[i - 1] = ey[i];
    }

    // Move (x1, y1) to the 5th position (index 4)
    y[4] = firstY;
    ey[4] = firstEY;

    // Update the graph with the rearranged points
    for (int i = 0; i < n; ++i)
    {
        g1->SetPoint(i, x[i], y[i]);
        g1->SetPointError(i, ex[i], ey[i]);
    }

    // Clean up temporary arrays
    delete[] x;
    delete[] y;
    delete[] ex;
    delete[] ey;
}

void changeordersub(TGraphErrors *g1)
{
    int n = g1->GetN();

    if (n < 2)
    {
        std::cerr << "Graph must have at least two points to rearrange." << std::endl;
        return;
    }

    // Temporary arrays for the rearranged points
    double *x = new double[n];
    double *y = new double[n];
    double *ex = new double[n];
    double *ey = new double[n];

    // Extract current points and print them
    /*std::cout << "Original Points:" << std::endl;*/
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
        /*std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;*/
    }

    // Rearrange the y-values: move y2, y3, ..., yn to the front, and y1 to the end
    double firstY = y[0]; // Store the first y-value
    double firstEY = ey[0];

    for (int i = 0; i < n - 1; ++i)
    {
        y[i] = y[i + 1];   // Shift all y-values left
        ey[i] = ey[i + 1]; // Shift all y-errors left
    }
    y[n - 1] = firstY;   // Move the first y-value to the last position
    ey[n - 1] = firstEY; // Move the first y-error to the last position

    // Update the graph with the rearranged points
    for (int i = 0; i < n; ++i)
    {
        g1->SetPoint(i, x[i], y[i]);
        g1->SetPointError(i, ex[i], ey[i]);
    }

    // Print updated points
    /*std::cout << "\nUpdated Points:" << std::endl;*/
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
        /*std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;*/
    }

    // Clean up temporary arrays
    delete[] x;
    delete[] y;
    delete[] ex;
    delete[] ey;
}

void changeorderfrank(TGraphErrors *g1, double shift)
{
    int n = g1->GetN(); // Number of points in the graph

    // Temporary variables to hold current points
    double x, y, ex, ey;

    // std::cout << "Before Shift:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y); // Get current x and y
        ex = g1->GetErrorX(i); // Get x error
        ey = g1->GetErrorY(i); // Get y error

        /*std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;*/

        // Shift the x value
        x += shift;

        // Update the graph
        g1->SetPoint(i, x, y);
        g1->SetPointError(i, ex, ey); // Errors remain unchanged
    }

    // std::cout << "\nAfter Shift:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y); // Get updated x and y
        ex = g1->GetErrorX(i); // Get x error
        ey = g1->GetErrorY(i); // Get y error

        /*std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;*/
    }
}

TGraphErrors *subtractppfromHI(TGraphErrors *g1)
{

    if (g1 == nullptr)
    {
        return nullptr;
    }

    int n = g1->GetN(); // Number of points in the graph
    if (n < 2)
    {
        std::cerr << "Graph must have at least two points to perform subtraction." << std::endl;
        return nullptr;
    }

    // Get the last point's y-value and error
    double x_last, y_last, ex_last, ey_last;
    g1->GetPoint(n - 1, x_last, y_last);
    ex_last = g1->GetErrorX(n - 1);
    ey_last = g1->GetErrorY(n - 1);

    // Create a new TGraphErrors for the modified points
    TGraphErrors *g_new = new TGraphErrors(n - 1);

    // Loop through all points except the last one
    for (int i = 0; i < n - 1; ++i)
    {
        double x, y, ex, ey;
        g1->GetPoint(i, x, y);
        ex = g1->GetErrorX(i);
        ey = g1->GetErrorY(i);

        // Subtract the last point's y-value and propagate errors quadratically
        double y_new = y - y_last;
        double ey_new = std::sqrt(ey * ey + ey_last * ey_last);

        // Add new point to the new graph
        g_new->SetPoint(i, x, y_new);
        g_new->SetPointError(i, ex, ey_new);
    }

    return g_new; // Return the new TGraphErrors
}
void subtractconstantfromHI(TGraphErrors *g1, double value, double valueErr)
{
    int n = g1->GetN(); // Number of points in the graph

    // Temporary arrays to store updated y-values and errors
    double x, y, ex, ey;

    /*std::cout << "Before Subtraction:" << std::endl;*/
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y); // Get the x and y values
        ex = g1->GetErrorX(i); // Get x error
        ey = g1->GetErrorY(i); // Get y error

        /*std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;*/

        // Subtract the value and propagate the error
        y -= value;                                    // Subtract the constant value
        ey = std::sqrt(ey * ey + valueErr * valueErr); // Combine errors quadratically

        // Update the graph
        g1->SetPoint(i, x, y);
        g1->SetPointError(i, ex, ey);
    }

    /*std::cout << "\nAfter Subtraction:" << std::endl;*/
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y);
        ex = g1->GetErrorX(i);
        ey = g1->GetErrorY(i);
        /*std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;*/
    }
}
TGraphErrors *addpppoint(TGraphErrors *g1, double value, double valueErr)
{
    int n = g1->GetN();

    if (n < 2)
    {
        std::cerr << "Graph must have at least two points to rearrange." << std::endl;
        return nullptr;
    }

    // Temporary arrays for the rearranged points
    double *x = new double[n + 1];
    double *y = new double[n + 1];
    double *ex = new double[n + 1];
    double *ey = new double[n + 1];

    // Extract current points and print them
    // std::cout << "Original Points:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
        /*std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;*/
    }

    x[n] = n + 1;
    ex[n] = 0;
    y[n] = value;
    ey[n] = valueErr;

    TGraphErrors *g2 = new TGraphErrors(n + 1, x, y, ex, ey);

    // cout << "# of points is" << g2->GetN() << endl;

    // Print updated points
    // std::cout << "\nUpdated Points:" << std::endl;
    for (int i = 0; i < n + 1; ++i)
    {
        g2->GetPoint(i, x[i], y[i]);
        ex[i] = g2->GetErrorX(i);
        ey[i] = g2->GetErrorY(i);
        /*std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;*/
    }

    // Clean up temporary arrays
    delete[] x;
    delete[] y;
    delete[] ex;
    delete[] ey;

    return g2;
}

void drawsubtractionplot(TCanvas *c1, TGraphErrors *g1, std::vector<double> &g1_syst, TGraphErrors *g2 = nullptr, const std::vector<double> &g2_syst = std::vector<double>{}, TGraphErrors *g3 = nullptr, const std::vector<double> &g3_syst = std::vector<double>{}, bool iseta = 0, bool isdM = 0)
{

    TString savingname;
    if (iseta)
    {
        if (isdM)
            savingname = "./plots/HI-pp/eta_dM_HI-pp.png";
        else
            savingname = "./plots/HI-pp/eta_dW_HI-pp.png";
    }
    if (!iseta)
    {
        if (isdM)
            savingname = "./plots/HI-pp/FA_dM_HI-pp.png";
        if (!isdM)
            savingname = "./plots/HI-pp/FA_dW_HI-pp.png";
    }

    c1->cd();
    if (isdM)
        g1->GetYaxis()->SetTitle("#DeltaM (GeV)");
    if (!isdM)
        g1->GetYaxis()->SetTitle("#DeltaWidth (GeV)");
    g1->GetXaxis()->SetTitle("Centrality");
    g1->SetLineColor(kBlack);
    g1->SetMarkerColor(kBlack);
    g1->SetMarkerStyle(20); // Full circle
    g1->SetMarkerSize(1.2);
    g1->SetLineWidth(2);
    g1->GetYaxis()->SetRangeUser(-0.8, 0.8);

    g1->GetXaxis()->SetLimits(0.5, 5.5);
    g1->GetXaxis()->SetRangeUser(0.5, 5.5);
    g1->GetXaxis()->SetNdivisions(5, 0, 0, kFALSE);
    g1->GetXaxis()->SetLabelSize(0);

    g1->GetXaxis()->ChangeLabel(5, 0, 0.04, 11, -1, -1, "  0-100%");
    g1->GetXaxis()->ChangeLabel(1, 0, 0.04, 11, -1, -1, "    0-10%");
    g1->GetXaxis()->ChangeLabel(2, 0, 0.04, 11, -1, -1, "  10-20%");
    g1->GetXaxis()->ChangeLabel(3, 0, 0.04, 11, -1, -1, "  20-30%");
    g1->GetXaxis()->ChangeLabel(4, 0, 0.04, 11, -1, -1, " 30-100%");
    g1->GetXaxis()->SetLabelOffset(0.03);

    g1->Draw("AP");

    // **Draw Floating Boxes for Systematic Uncertainty**
    int n = g1->GetN();
    std::vector<TBox *> systBoxes;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        g1->GetPoint(i, x, y);
        double systError = g1_syst[i]; // Systematic error

        // Define box boundaries (small width in X to appear as floating)
        double xMin = x - 0.05; // Slight offset in X to make it visible
        double xMax = x + 0.05;
        double yMin = y - systError;
        double yMax = y + systError;

        // Create and style the box
        TBox *box = new TBox(xMin, yMin, xMax, yMax);
        box->SetFillStyle(0);      // Hollow box (no fill)
        box->SetLineColor(kBlack); // Red border
        box->SetLineWidth(2);      // Border thickness
        box->SetLineStyle(2);      // Dashed line style
        box->Draw("same");

        // Store box in vector for memory management
        systBoxes.push_back(box);
    }

    TLine *line = new TLine(0.5, 0, 5.5, 0);
    line->SetLineColor(kBlack); // Set line color (optional)
    line->SetLineWidth(2);      // Set line width (optional)
    line->SetLineStyle(2);      // Set line style: 1=solid, 2=dashed, etc. (optional)
    line->Draw("SAME");

    g2->SetLineColor(kRed);
    g2->SetMarkerColor(kRed);
    g2->SetLineStyle(1);    // Solid line
    g2->SetMarkerStyle(21); // Full circle
    g2->SetMarkerSize(1.2);
    g2->SetLineWidth(3);
    g2->Draw("P SAME");

    int n2 = g2->GetN();
    std::vector<TBox *> systBoxes2;

    for (int i = 0; i < n2; i++)
    {
        double x, y;
        g2->GetPoint(i, x, y);
        double systError = g2_syst[i]; // Systematic error

        // Define box boundaries (small width in X to appear as floating)
        double xMin = x - 0.05; // Slight offset in X to make it visible
        double xMax = x + 0.05;
        double yMin = y - systError;
        double yMax = y + systError;

        // Create and style the box
        TBox *box = new TBox(xMin, yMin, xMax, yMax);
        box->SetFillStyle(0);    // Hollow box (no fill)
        box->SetLineColor(kRed); // Red border
        box->SetLineWidth(2);    // Border thickness
        box->SetLineStyle(2);    // Dashed line style
        box->Draw("same");

        // Store box in vector for memory management
        systBoxes2.push_back(box);
    }

    g3->SetLineColor(kBlue);
    g3->SetMarkerColor(kBlue);
    g3->SetMarkerStyle(24); // Full circle
    g3->SetMarkerSize(1.2);
    g3->SetLineStyle(1); // Dashed line
    g3->SetLineWidth(2);
    g3->Draw("P SAME");

    int n3 = g3->GetN();
    std::vector<TBox *> systBoxes3;

    for (int i = 0; i < n3; i++)
    {
        if (g3_syst.size() == 0)
        {
            break;
        }
        double x, y;
        g3->GetPoint(i, x, y);
        double systError = g3_syst[i]; // Systematic error

        // Define box boundaries (small width in X to appear as floating)
        double xMin = x - 0.05; // Slight offset in X to make it visible
        double xMax = x + 0.05;
        double yMin = y - systError;
        double yMax = y + systError;

        // Create and style the box
        TBox *box = new TBox(xMin, yMin, xMax, yMax);
        box->SetFillStyle(0);     // Hollow box (no fill)
        box->SetLineColor(kBlue); // Red border
        box->SetLineWidth(2);     // Border thickness
        box->SetLineStyle(2);     // Dashed line style
        box->Draw("same");

        // Store box in vector for memory management
        systBoxes3.push_back(box);
    }

    TLegend *legend = new TLegend(0.55, 0.75, 0.95, 0.9);
    if (isdM)
    {
        legend->AddEntry(g1, "Template shift", "lp");
        legend->AddEntry(g2, "Fit mean", "lp");
        legend->AddEntry(g3, "Window Counting mean", "lp");
    }
    if (!isdM)
    {
        legend->AddEntry(g1, "Template shift", "lp");
        legend->AddEntry(g2, "Fit sigma", "lp");
        legend->AddEntry(g3, "Window Counting RMS", "lp");
    }

    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();

    TLatex latex;
    latex.SetTextFont(42);
    latex.SetTextSize(0.03);
    latex.SetTextAlign(11); // Left alignment

    // Add the text
    if (iseta)
    {
        latex.DrawLatex(1.0, 0.45, "|#eta| < 1");
    }
    if (!iseta)
    {

        latex.DrawLatex(1.0, 0.45, "|#eta| < 2.4");
        // latex.DrawLatex(1.0, 0.35, "temp bk sub");
    }

    CMS_lumi(c1, 13, 10);

    c1->SaveAs(savingname);
}

void drawHIppplot(TCanvas *c1 = nullptr, TGraphErrors *g1 = nullptr, const std::vector<double> &g1_syst = std::vector<double>{}, TGraphErrors *g2 = nullptr, const std::vector<double> &g2_syst = std::vector<double>{}, TGraphErrors *g3 = nullptr, const std::vector<double> &g3_syst = std::vector<double>{}, bool iseta = false, bool isdM = false)
{
    TString savingname;

    if (iseta)
    {
        if (isdM)
            savingname = "./plots/HIandpp/eta_dM_HIandpp.png";
        else
            savingname = "./plots/HIandpp/eta_dW_HIandpp.png";
    }
    if (!iseta)
    {
        if (isdM)
            savingname = "./plots/HIandpp/FA_dM_HIandpp.png";
        if (!isdM)
            savingname = "./plots/HIandpp/FA_dW_HIandpp.png";
    }

    c1->cd();
    if (isdM)
        g1->GetYaxis()->SetTitle("M (GeV)");
    if (!isdM)
        g1->GetYaxis()->SetTitle("Width (GeV)");
    g1->GetXaxis()->SetTitle("Centrality");
    g1->SetLineColor(kBlack);
    g1->SetMarkerColor(kBlack);
    g1->SetMarkerStyle(20); // Full circle
    g1->SetMarkerSize(1.2);
    g1->SetLineWidth(2);
    if (isdM)
        g1->GetYaxis()->SetRangeUser(89.5, 92.5);
    if (!isdM)
        g1->GetYaxis()->SetRangeUser(0.5, 5.5);

    g1->GetXaxis()->SetLimits(0.5, 6.5);
    g1->GetXaxis()->SetRangeUser(0.5, 6.5);
    g1->GetXaxis()->SetNdivisions(6, 0, 0, kFALSE);
    g1->GetXaxis()->SetLabelSize(0);

    g1->GetXaxis()->ChangeLabel(6, 0, 0.035, 11, -1, -1, "      pp");
    g1->GetXaxis()->ChangeLabel(5, 0, 0.035, 11, -1, -1, "  0-100%");
    g1->GetXaxis()->ChangeLabel(1, 0, 0.035, 11, -1, -1, "   0-10%");
    g1->GetXaxis()->ChangeLabel(2, 0, 0.035, 11, -1, -1, "  10-20%");
    g1->GetXaxis()->ChangeLabel(3, 0, 0.035, 11, -1, -1, "  20-30%");
    g1->GetXaxis()->ChangeLabel(4, 0, 0.035, 11, -1, -1, " 30-100%");
    g1->GetXaxis()->SetLabelOffset(0.03);

    g1->Draw("AP");

    // **Draw Floating Boxes for Systematic Uncertainty**
    int n = g1->GetN();
    std::vector<TBox *> systBoxes;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        g1->GetPoint(i, x, y);
        double systError = g1_syst[i]; // Systematic error

        // Define box boundaries (small width in X to appear as floating)
        double xMin = x - 0.05; // Slight offset in X to make it visible
        double xMax = x + 0.05;
        double yMin = y - systError;
        double yMax = y + systError;

        // Create and style the box
        TBox *box = new TBox(xMin, yMin, xMax, yMax);
        box->SetFillStyle(0);      // Hollow box (no fill)
        box->SetLineColor(kBlack); // Red border
        box->SetLineWidth(2);      // Border thickness
        box->SetLineStyle(2);      // Dashed line style
        box->Draw("same");

        // Store box in vector for memory management
        systBoxes.push_back(box);
    }

    g2->SetLineColor(kRed);
    g2->SetMarkerColor(kRed);
    g2->SetLineStyle(1);    // Solid line
    g2->SetMarkerStyle(21); // Full circle
    g2->SetMarkerSize(1.2);
    g2->SetLineWidth(3);
    g2->Draw("P SAME");

    int n2 = g2->GetN();
    std::vector<TBox *> systBoxes2;

    for (int i = 0; i < n2; i++)
    {
        double x, y;
        g2->GetPoint(i, x, y);
        double systError = g2_syst[i]; // Systematic error

        // Define box boundaries (small width in X to appear as floating)
        double xMin = x - 0.05; // Slight offset in X to make it visible
        double xMax = x + 0.05;
        double yMin = y - systError;
        double yMax = y + systError;

        // Create and style the box
        TBox *box = new TBox(xMin, yMin, xMax, yMax);
        box->SetFillStyle(0);    // Hollow box (no fill)
        box->SetLineColor(kRed); // Red border
        box->SetLineWidth(2);    // Border thickness
        box->SetLineStyle(2);    // Dashed line style
        box->Draw("same");

        // Store box in vector for memory management
        systBoxes2.push_back(box);
    }

    g3->SetLineColor(kBlue);
    g3->SetMarkerColor(kBlue);
    g3->SetMarkerStyle(24); // Full circle
    g3->SetMarkerSize(1.2);
    g3->SetLineStyle(1); // Dashed line
    g3->SetLineWidth(2);
    g3->Draw("P SAME");

    int n3 = g3->GetN();
    std::vector<TBox *> systBoxes3;

    for (int i = 0; i < n3; i++)
    {
        if (g3_syst.size() == 0)
        {
            break;
        }
        double x, y;
        g3->GetPoint(i, x, y);
        double systError = g3_syst[i]; // Systematic error

        // Define box boundaries (small width in X to appear as floating)
        double xMin = x - 0.05; // Slight offset in X to make it visible
        double xMax = x + 0.05;
        double yMin = y - systError;
        double yMax = y + systError;

        // Create and style the box
        TBox *box = new TBox(xMin, yMin, xMax, yMax);
        box->SetFillStyle(0);     // Hollow box (no fill)
        box->SetLineColor(kBlue); // Red border
        box->SetLineWidth(2);     // Border thickness
        box->SetLineStyle(2);     // Dashed line style
        box->Draw("same");

        // Store box in vector for memory management
        systBoxes3.push_back(box);
    }

    g1->Draw("P SAME");

    TLine *line_g1 = new TLine(0.5, g1->GetPointY(5), 6.5, g1->GetPointY(5));
    line_g1->SetLineColor(kBlack); // Set line color (optional)
    line_g1->SetLineWidth(2);      // Set line width (optional)
    line_g1->SetLineStyle(2);      // Set line style: 1=solid, 2=dashed, etc. (optional)
    line_g1->Draw("SAME");

    TLine *line_g2 = new TLine(0.5, g2->GetPointY(5), 6.5, g2->GetPointY(5));
    line_g2->SetLineColor(kRed); // Set line color (optional)
    line_g2->SetLineWidth(2);    // Set line width (optional)
    line_g2->SetLineStyle(2);    // Set line style: 1=solid, 2=dashed, etc. (optional)
    line_g2->Draw("SAME");

    TLine *line_g3 = new TLine(0.5, g3->GetPointY(5), 6.5, g3->GetPointY(5));
    line_g3->SetLineColor(kBlue); // Set line color (optional)
    line_g3->SetLineWidth(2);     // Set line width (optional)
    line_g3->SetLineStyle(2);     // Set line style: 1=solid, 2=dashed, etc. (optional)
    line_g3->Draw("SAME");

    TLegend *legend = new TLegend(0.55, 0.7, 0.95, 0.9);
    if (isdM)
    {
        legend->AddEntry(g1, "Template shift", "lp");
        legend->AddEntry(line_g1, "Template pp", "l");
        legend->AddEntry(g2, "Fit mean", "lp");
        legend->AddEntry(line_g2, "Fit pp", "l");
        legend->AddEntry(g3, "Window Counting mean", "lp");
        legend->AddEntry(line_g3, "Window Counting pp", "l");
    }
    if (!isdM)
    {
        legend->AddEntry(g1, "Template shift", "lp");
        legend->AddEntry(line_g1, "Template pp", "l");
        legend->AddEntry(g2, "Fit sigma", "lp");
        legend->AddEntry(line_g2, "Fit pp", "l");
        legend->AddEntry(g3, "Window Counting RMS", "lp");
        legend->AddEntry(line_g3, "Window Counting pp", "l");
    }
    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();

    TLatex latex;
    latex.SetTextFont(42);
    latex.SetTextSize(0.03);
    latex.SetTextAlign(11); // Left alignment

    // Add the text
    if (iseta)
    {
        if (isdM)
            latex.DrawLatex(1.0, 91.7, "|#eta| < 1");
        if (!isdM)
            latex.DrawLatex(1.0, 4.5, "|#eta| < 1");
    }

    if (!iseta)
    {

        if (isdM)
            latex.DrawLatex(1.0, 91.7, "|#eta| < 2.4");
        if (!isdM)
            latex.DrawLatex(1.0, 4.5, "|#eta| < 2.4");
    }

    CMS_lumi(c1, 13, 10);

    c1->SaveAs(savingname);
}

void computeSystematicUncertainty(TGraphErrors *nominal, TGraphErrors *g1, TGraphErrors *g2, TGraphErrors *g3,
                                  TGraphErrors *g4, TGraphErrors *g5, TGraphErrors *g6, TGraphErrors *g7, TGraphErrors *g8,
                                  std::vector<double> &systematicErrors)
{
    int n = nominal->GetN();
    if (n != g1->GetN())
    {
        std::cerr << "Error: Nominal and variation graphs must have the same number of points!" << std::endl;
        return;
    }

    std::vector<double> xValues(n);
    std::vector<double> yValues(n);
    std::vector<double> yStatErrors(n);
    std::vector<double> ySystErrors(n);

    // Loop over points
    for (int i = 0; i < n; ++i)
    {
        double y_nominalvalue;
        double y_tnpUvalue;
        double y_tnpDvalue;
        double y_acooffvalue;
        double y_no_bkvalue;
        double y_uniformvalue;
        double y_mass_rangevalue;
        double y_HF_up;
        double y_HF_down;

        double x_nominalvalue;
        double x_tnpUvalue;
        double x_tnpDvalue;
        double x_acooffvalue;
        double x_no_bkvalue;
        double x_uniformvalue;
        double x_mass_rangevalue;
        double x_HF_up;
        double x_HF_down;

        nominal->GetPoint(i, x_nominalvalue, y_nominalvalue);
        g1->GetPoint(i, x_tnpUvalue, y_tnpUvalue);
        g2->GetPoint(i, x_tnpDvalue, y_tnpDvalue);
        g3->GetPoint(i, x_acooffvalue, y_acooffvalue);
        g4->GetPoint(i, x_no_bkvalue, y_no_bkvalue);
        g5->GetPoint(i, x_uniformvalue, y_uniformvalue);
        g6->GetPoint(i, x_mass_rangevalue, y_mass_rangevalue);
        g7->GetPoint(i, x_HF_up, y_HF_up);
        g8->GetPoint(i, x_HF_down, y_HF_down);

        double tnpU_syst = abs(y_tnpUvalue - y_nominalvalue);
        double tnpD_syst = abs(y_tnpDvalue - y_nominalvalue);
        double acooff_syst = abs(y_acooffvalue - y_nominalvalue);
        double no_bk_syst = abs(y_no_bkvalue - y_nominalvalue);
        double uniform_syst = abs(y_uniformvalue - y_nominalvalue);
        double mass_range_syst = abs(y_mass_rangevalue - y_nominalvalue);
        double HF_up_syst = abs(y_HF_up - y_nominalvalue);
        double HF_down_syst = abs(y_HF_down - y_nominalvalue);

        double finalHFsyst;

        if (HF_up_syst > HF_down_syst)
        {
            finalHFsyst = HF_up_syst;
        }
        else
        {
            finalHFsyst = HF_down_syst;
        }

        double totalsyst = tnpU_syst * tnpU_syst + tnpD_syst * tnpD_syst + acooff_syst * acooff_syst + no_bk_syst * no_bk_syst + mass_range_syst * mass_range_syst + finalHFsyst * finalHFsyst;
        totalsyst = sqrt(totalsyst);

        systematicErrors.push_back(totalsyst);
    }
}
void computeSystematicUncertaintyfrank(TGraphErrors *nominal, TGraphErrors *g1, TGraphErrors *g2, TGraphErrors *g3,
                                       std::vector<double> &systematicErrors)
{
    int n = nominal->GetN();
    if (n != g1->GetN())
    {
        std::cerr << "Error: Nominal and variation graphs must have the same number of points!" << std::endl;
        return;
    }

    std::vector<double> xValues(n);
    std::vector<double> yValues(n);
    std::vector<double> yStatErrors(n);
    std::vector<double> ySystErrors(n);

    // Loop over points
    for (int i = 0; i < n; ++i)
    {
        double y_nominalvalue;
        double y_changesigvalue;
        double y_linearbackgroundvalue;
        double y_CBvalue;

        double x_nominalvalue;
        double x_changesigvalue;
        double x_linearbackgroundvalue;
        double x_CBvalue;

        nominal->GetPoint(i, x_nominalvalue, y_nominalvalue);
        g1->GetPoint(i, x_changesigvalue, y_changesigvalue);
        g2->GetPoint(i, x_linearbackgroundvalue, y_linearbackgroundvalue);
        g3->GetPoint(i, x_CBvalue, y_CBvalue);

        double changesig_syst = abs(y_changesigvalue - y_nominalvalue);
        double linear_syst = abs(y_linearbackgroundvalue - y_nominalvalue);
        double CB_syst = abs(y_CBvalue - y_nominalvalue);

        double totalsyst = changesig_syst * changesig_syst + linear_syst * linear_syst + CB_syst * CB_syst;
        totalsyst = sqrt(totalsyst);

        systematicErrors.push_back(totalsyst);
    }
}
void computeSystematicUncertaintyfrankWindow(TGraphErrors *nominal, TGraphErrors *g1, TGraphErrors *g2,
                                             std::vector<double> &systematicErrors)
{
    if (nominal == nullptr)
    {
        cout << "Missing hist for windowcounting systematic calculation!!" << endl;
        return;
    }
    int n = nominal->GetN();
    if (n != g1->GetN())
    {
        std::cerr << "Error: Nominal and variation graphs must have the same number of points!" << std::endl;
        return;
    }

    std::vector<double> xValues(n);
    std::vector<double> yValues(n);
    std::vector<double> yStatErrors(n);
    std::vector<double> ySystErrors(n);

    // Loop over points
    for (int i = 0; i < n; ++i)
    {
        double y_nominalvalue;
        double y_3gamma;
        double y_5gamma;

        double x_nominalvalue;
        double x_3gamma;
        double x_5gamma;

        nominal->GetPoint(i, x_nominalvalue, y_nominalvalue);
        g1->GetPoint(i, x_3gamma, y_3gamma);
        g2->GetPoint(i, x_5gamma, y_5gamma);

        double val_3_gamma_syst = abs(y_3gamma - y_nominalvalue);
        double val_5_gamma_syst = abs(y_5gamma - y_nominalvalue);

        double totalsyst = 0;

        if (val_3_gamma_syst > val_5_gamma_syst)
        {
            totalsyst = val_3_gamma_syst;
        }
        else
        {
            totalsyst = val_5_gamma_syst;
        }

        /*double totalsyst = changesig_syst * changesig_syst + linear_syst * linear_syst + CB_syst * CB_syst;
        totalsyst = sqrt(totalsyst);*/

        systematicErrors.push_back(totalsyst);
    }
}
void mergeplot(bool iseta = 1)
{
    // one is pp + HI Points, without subtracting.
    // one is HI Points, with pp subtracted.
    setTDRStyle();

    // nominal, changesig, linear, CB

    // Frank's Place :)
    TFile *fit_nominal;
    TFile *fit_changesig;
    TFile *fit_linear;
    TFile *fit_CB;
    TFile *rms_nominal;
    TFile *rms_FA_syst;

    rms_nominal = new TFile("./RMS/ppPbPbCentMeanRMS_bkgd_subtracted_test.root", "READ");
    rms_FA_syst = new TFile("./RMS/SystematicsRMSWindowGraphs.root", "READ");

    if (iseta)
    {
        fit_nominal = new TFile("./Frank'sfit/PbPbCentDiff_Barrel3v4.root", "READ");
        fit_changesig = new TFile("./Frank'sfit/PbPbCentDiff_ADSCB_Exp_Barrel.root", "READ");
        fit_linear = new TFile("./Frank'sfit/PbPbCentDiff_ADSCB_Line_Barrel.root", "READ");
        fit_CB = new TFile("./Frank'sfit/PbPbCentDiff_CB_Exp_Barrel.root", "READ");
    }
    if (!iseta)
    {
        fit_nominal = new TFile("./Frank'sfit/PbPbCentDiff_WA3v4.root", "READ");
        fit_changesig = new TFile("./Frank'sfit/PbPbCentDiff_ADSCB_Exp_WA.root", "READ");
        fit_linear = new TFile("./Frank'sfit/PbPbCentDiff_ADSCB_Line_WA.root", "READ");
        fit_CB = new TFile("./Frank'sfit/PbPbCentDiff_CB_Exp_WA.root", "READ");
    }

    readfrankplot(fit_nominal, 1);
    readfrankplot(fit_changesig, 2);
    readfrankplot(fit_linear, 3);
    readfrankplot(fit_CB, 4);

    readfrankplotrms(rms_nominal, rms_FA_syst, iseta);

    // Zheng's Place :(

    TFile *f_2 = new TFile("./Zheng'stemplate/nominal_syst_tgraph.root", "READ");
    readplot(f_2, iseta);

    // move 0-100 to second last position
    changeorderand(g_zh_HI_dM_nominal);
    changeorderand(g_zh_HI_dM_tnpU);
    changeorderand(g_zh_HI_dM_tnpD);
    changeorderand(g_zh_HI_dM_acooff);
    changeorderand(g_zh_HI_dM_nominal_no_bk);
    changeorderand(g_zh_HI_dM_nominal_uniform_rebin);
    changeorderand(g_zh_HI_dM_nominal_mass_range);
    changeorderand(g_zh_HI_dM_HF_up);
    changeorderand(g_zh_HI_dM_HF_down);

    changeorderand(g_zh_HI_dW_nominal);
    changeorderand(g_zh_HI_dW_tnpU);
    changeorderand(g_zh_HI_dW_tnpD);
    changeorderand(g_zh_HI_dW_acooff);
    changeorderand(g_zh_HI_dW_nominal_no_bk);
    changeorderand(g_zh_HI_dW_nominal_uniform_rebin);
    changeorderand(g_zh_HI_dW_nominal_mass_range);
    changeorderand(g_zh_HI_dW_HF_up);
    changeorderand(g_zh_HI_dW_HF_down);

    changeorderfrank(g_frank_fit_dM_nominal, +1);
    changeorderfrank(g_frank_fit_dM_changesig, +1);
    changeorderfrank(g_frank_fit_dM_linearbackground, +1);
    changeorderfrank(g_frank_fit_dM_CB, +1);

    changeorderfrank(g_frank_fit_dW_nominal, +1);
    changeorderfrank(g_frank_fit_dW_changesig, +1);
    changeorderfrank(g_frank_fit_dW_linearbackground, +1);
    changeorderfrank(g_frank_fit_dW_CB, +1);

    /*changeorderfrank(g_frank_rms_dM_nominal, +1);
    changeorderfrank(g_frank_rms_dW_nominal, +1);*/

    double frank_fit_pp_dM_nominal = h_frank_fit_pp_dM_nominal->GetBinContent(1);
    double frank_fit_pp_dM_changesig = h_frank_fit_pp_dM_changesig->GetBinContent(1);
    double frank_fit_pp_dM_linearbackground = h_frank_fit_pp_dM_linearbackground->GetBinContent(1);
    double frank_fit_pp_dM_CB = h_frank_fit_pp_dM_CB->GetBinContent(1);

    double frank_fit_pp_dW_nominal = h_frank_fit_pp_dW_nominal->GetBinContent(1);
    double frank_fit_pp_dW_changesig = h_frank_fit_pp_dW_changesig->GetBinContent(1);
    double frank_fit_pp_dW_linearbackground = h_frank_fit_pp_dW_linearbackground->GetBinContent(1);
    double frank_fit_pp_dW_CB = h_frank_fit_pp_dW_CB->GetBinContent(1);

    double frank_fit_pp_dM_nominal_err = h_frank_fit_pp_dM_nominal->GetBinError(1);
    double frank_fit_pp_dM_changesig_err = h_frank_fit_pp_dM_changesig->GetBinError(1);
    double frank_fit_pp_dM_linearbackground_err = h_frank_fit_pp_dM_linearbackground->GetBinError(1);
    double frank_fit_pp_dM_CB_err = h_frank_fit_pp_dM_CB->GetBinError(1);

    double frank_fit_pp_dW_nominal_err = h_frank_fit_pp_dW_nominal->GetBinError(1);
    double frank_fit_pp_dW_changesig_err = h_frank_fit_pp_dW_changesig->GetBinError(1);
    double frank_fit_pp_dW_linearbackground_err = h_frank_fit_pp_dW_linearbackground->GetBinError(1);
    double frank_fit_pp_dW_CB_err = h_frank_fit_pp_dW_CB->GetBinError(1);

    double frank_window_pp_dM_nominal = g_frank_rms_pp_dM_nominal->GetBinContent(1);
    double frank_window_pp_dM_nominal_err = g_frank_rms_pp_dM_nominal->GetBinError(1);
    double frank_window_pp_dW_nominal = g_frank_rms_pp_dW_nominal->GetBinContent(1);
    double frank_window_pp_dW_nominal_err = g_frank_rms_pp_dW_nominal->GetBinError(1);

    g_frank_fit_dM_nominal = addpppoint(g_frank_fit_dM_nominal, frank_fit_pp_dM_nominal, frank_fit_pp_dM_nominal_err);
    g_frank_fit_dM_changesig = addpppoint(g_frank_fit_dM_changesig, frank_fit_pp_dM_changesig, frank_fit_pp_dM_changesig_err);
    g_frank_fit_dM_linearbackground = addpppoint(g_frank_fit_dM_linearbackground, frank_fit_pp_dM_linearbackground, frank_fit_pp_dM_linearbackground_err);
    g_frank_fit_dM_CB = addpppoint(g_frank_fit_dM_CB, frank_fit_pp_dM_CB, frank_fit_pp_dM_CB_err);

    g_frank_fit_dW_nominal = addpppoint(g_frank_fit_dW_nominal, frank_fit_pp_dW_nominal, frank_fit_pp_dW_nominal_err);
    g_frank_fit_dW_changesig = addpppoint(g_frank_fit_dW_changesig, frank_fit_pp_dW_changesig, frank_fit_pp_dW_changesig_err);
    g_frank_fit_dW_linearbackground = addpppoint(g_frank_fit_dW_linearbackground, frank_fit_pp_dW_linearbackground, frank_fit_pp_dW_linearbackground_err);
    g_frank_fit_dW_CB = addpppoint(g_frank_fit_dW_CB, frank_fit_pp_dW_CB, frank_fit_pp_dW_CB_err);

    g_frank_fit_dM_nominal_minuspp = subtractppfromHI(g_frank_fit_dM_nominal);
    g_frank_fit_dM_changesig_minuspp = subtractppfromHI(g_frank_fit_dM_changesig);
    g_frank_fit_dM_linearbackground_minuspp = subtractppfromHI(g_frank_fit_dM_linearbackground);
    g_frank_fit_dM_CB_minuspp = subtractppfromHI(g_frank_fit_dM_CB);

    g_frank_fit_dW_nominal_minuspp = subtractppfromHI(g_frank_fit_dW_nominal);
    g_frank_fit_dW_changesig_minuspp = subtractppfromHI(g_frank_fit_dW_changesig);
    g_frank_fit_dW_linearbackground_minuspp = subtractppfromHI(g_frank_fit_dW_linearbackground);
    g_frank_fit_dW_CB_minuspp = subtractppfromHI(g_frank_fit_dW_CB);

    g_frank_rms_dM_nominal = addpppoint(g_frank_rms_dM_nominal, frank_window_pp_dM_nominal, frank_window_pp_dM_nominal_err);
    g_frank_rms_dW_nominal = addpppoint(g_frank_rms_dW_nominal, frank_window_pp_dW_nominal, frank_window_pp_dW_nominal_err);

    g_frank_rms_dM_nominal_minuspp = subtractppfromHI(g_frank_rms_dM_nominal);
    g_frank_rms_dW_nominal_minuspp = subtractppfromHI(g_frank_rms_dW_nominal);

    g_frank_rms_pesudo_dM_3gamma_minuspp = subtractppfromHI(g_frank_rms_pesudo_dM_3gamma);
    g_frank_rms_pesudo_dM_4gamma_minuspp = subtractppfromHI(g_frank_rms_pesudo_dM_4gamma);
    g_frank_rms_pesudo_dM_5gamma_minuspp = subtractppfromHI(g_frank_rms_pesudo_dM_5gamma);

    g_frank_rms_pesudo_dW_3gamma_minuspp = subtractppfromHI(g_frank_rms_pesudo_dW_3gamma);
    g_frank_rms_pesudo_dW_4gamma_minuspp = subtractppfromHI(g_frank_rms_pesudo_dW_4gamma);
    g_frank_rms_pesudo_dW_5gamma_minuspp = subtractppfromHI(g_frank_rms_pesudo_dW_5gamma);

    // move 0-100 to last position
    changeordersub(g_zh_HI_dM_nominal_minuspp);
    changeordersub(g_zh_HI_dM_tnpU_minuspp);
    changeordersub(g_zh_HI_dM_tnpD_minuspp);
    changeordersub(g_zh_HI_dM_acooff_minuspp);
    changeordersub(g_zh_HI_dM_nominal_no_bk_minuspp);
    changeordersub(g_zh_HI_dM_nominal_uniform_rebin_minuspp);
    changeordersub(g_zh_HI_dM_nominal_mass_range_minuspp);
    changeordersub(g_zh_HI_dM_HF_down_minuspp);
    changeordersub(g_zh_HI_dM_HF_up_minuspp);

    changeordersub(g_zh_HI_dW_nominal_minuspp);
    changeordersub(g_zh_HI_dW_tnpU_minuspp);
    changeordersub(g_zh_HI_dW_tnpD_minuspp);
    changeordersub(g_zh_HI_dW_acooff_minuspp);
    changeordersub(g_zh_HI_dW_nominal_no_bk_minuspp);
    changeordersub(g_zh_HI_dW_nominal_uniform_rebin_minuspp);
    changeordersub(g_zh_HI_dW_nominal_mass_range_minuspp);
    changeordersub(g_zh_HI_dW_HF_up_minuspp);
    changeordersub(g_zh_HI_dW_HF_down_minuspp);

    vector<double> HI_pp_dM_syst;
    vector<double> HI_pp_dW_syst;
    vector<double> HI_sub_pp_dM_syst;
    vector<double> HI_sub_pp_dW_syst;

    computeSystematicUncertainty(g_zh_HI_dM_nominal, g_zh_HI_dM_tnpU, g_zh_HI_dM_tnpD, g_zh_HI_dM_acooff, g_zh_HI_dM_nominal_no_bk,
                                 g_zh_HI_dM_nominal_uniform_rebin, g_zh_HI_dM_nominal_mass_range, g_zh_HI_dM_HF_up, g_zh_HI_dM_HF_down, HI_pp_dM_syst);
    computeSystematicUncertainty(g_zh_HI_dW_nominal, g_zh_HI_dW_tnpU, g_zh_HI_dW_tnpD, g_zh_HI_dW_acooff, g_zh_HI_dW_nominal_no_bk,
                                 g_zh_HI_dW_nominal_uniform_rebin, g_zh_HI_dW_nominal_mass_range, g_zh_HI_dW_HF_up, g_zh_HI_dW_HF_down, HI_pp_dW_syst);
    computeSystematicUncertainty(g_zh_HI_dM_nominal_minuspp, g_zh_HI_dM_tnpU_minuspp, g_zh_HI_dM_tnpD_minuspp, g_zh_HI_dM_acooff_minuspp, g_zh_HI_dM_nominal_no_bk_minuspp,
                                 g_zh_HI_dM_nominal_uniform_rebin_minuspp, g_zh_HI_dM_nominal_mass_range_minuspp, g_zh_HI_dM_HF_up_minuspp, g_zh_HI_dM_HF_down_minuspp, HI_sub_pp_dM_syst);
    computeSystematicUncertainty(g_zh_HI_dW_nominal_minuspp, g_zh_HI_dW_tnpU_minuspp, g_zh_HI_dW_tnpD_minuspp, g_zh_HI_dW_acooff_minuspp, g_zh_HI_dW_nominal_no_bk_minuspp,
                                 g_zh_HI_dW_nominal_uniform_rebin_minuspp, g_zh_HI_dW_nominal_mass_range_minuspp, g_zh_HI_dW_HF_up_minuspp, g_zh_HI_dW_HF_down_minuspp, HI_sub_pp_dW_syst);

    vector<double> HI_pp_dM_syst_fit;
    vector<double> HI_pp_dW_syst_fit;
    vector<double> HI_sub_pp_dM_syst_fit;
    vector<double> HI_sub_pp_dW_syst_fit;
    cout << "TEST" << endl;

    computeSystematicUncertaintyfrank(g_frank_fit_dM_nominal, g_frank_fit_dM_changesig, g_frank_fit_dM_linearbackground, g_frank_fit_dM_CB, HI_pp_dM_syst_fit);
    computeSystematicUncertaintyfrank(g_frank_fit_dW_nominal, g_frank_fit_dW_changesig, g_frank_fit_dW_linearbackground, g_frank_fit_dW_CB, HI_pp_dW_syst_fit);
    computeSystematicUncertaintyfrank(g_frank_fit_dM_nominal_minuspp, g_frank_fit_dM_changesig_minuspp, g_frank_fit_dM_linearbackground_minuspp, g_frank_fit_dM_CB_minuspp, HI_sub_pp_dM_syst_fit);
    computeSystematicUncertaintyfrank(g_frank_fit_dW_nominal_minuspp, g_frank_fit_dW_changesig_minuspp, g_frank_fit_dW_linearbackground_minuspp, g_frank_fit_dW_CB_minuspp, HI_sub_pp_dW_syst_fit);
    cout << "TEST1" << endl;

    vector<double> HI_pp_dM_syst_window;
    vector<double> HI_pp_dW_syst_window;
    vector<double> HI_sub_pp_dM_syst_window;
    vector<double> HI_sub_pp_dW_syst_window;

    computeSystematicUncertaintyfrankWindow(g_frank_rms_pesudo_dM_4gamma, g_frank_rms_pesudo_dM_3gamma, g_frank_rms_pesudo_dM_5gamma, HI_pp_dM_syst_window);
    computeSystematicUncertaintyfrankWindow(g_frank_rms_pesudo_dW_4gamma, g_frank_rms_pesudo_dW_3gamma, g_frank_rms_pesudo_dW_5gamma, HI_pp_dW_syst_window);
    computeSystematicUncertaintyfrankWindow(g_frank_rms_pesudo_dM_4gamma_minuspp, g_frank_rms_pesudo_dM_3gamma_minuspp, g_frank_rms_pesudo_dM_5gamma_minuspp, HI_sub_pp_dM_syst_window);
    computeSystematicUncertaintyfrankWindow(g_frank_rms_pesudo_dW_4gamma_minuspp, g_frank_rms_pesudo_dW_3gamma_minuspp, g_frank_rms_pesudo_dW_5gamma_minuspp, HI_sub_pp_dW_syst_window);
    cout << "TEST2" << endl;

    subtractconstantfromHI(g_zh_HI_dM_nominal, -91.1876, 0);
    subtractconstantfromHI(g_zh_HI_dW_nominal, -2.4955, 0);

    changeorderfrank(g_zh_HI_dM_nominal_minuspp, -0.1);
    changeorderfrank(g_zh_HI_dW_nominal_minuspp, -0.1);

    changeorderfrank(g_frank_rms_dM_nominal_minuspp, +0.1);
    changeorderfrank(g_frank_rms_dW_nominal_minuspp, +0.1);
    cout << "TEST3" << endl;

    TCanvas *c1 = new TCanvas("c1", "", 800, 800);
    drawsubtractionplot(c1, g_zh_HI_dM_nominal_minuspp, HI_sub_pp_dM_syst, g_frank_fit_dM_nominal_minuspp, HI_sub_pp_dM_syst_fit, g_frank_rms_dM_nominal_minuspp, HI_sub_pp_dM_syst_window, iseta, true);
    drawsubtractionplot(c1, g_zh_HI_dW_nominal_minuspp, HI_sub_pp_dW_syst, g_frank_fit_dW_nominal_minuspp, HI_sub_pp_dW_syst_fit, g_frank_rms_dW_nominal_minuspp, HI_sub_pp_dW_syst_window, iseta, false);
    TCanvas *c2 = new TCanvas("c2", "", 800, 800);
    drawHIppplot(c1, g_zh_HI_dM_nominal, HI_pp_dM_syst, g_frank_fit_dM_nominal, HI_pp_dM_syst_fit, g_frank_rms_dM_nominal, HI_pp_dM_syst_window, iseta, true);
    drawHIppplot(c1, g_zh_HI_dW_nominal, HI_pp_dW_syst, g_frank_fit_dW_nominal, HI_pp_dW_syst_fit, g_frank_rms_dW_nominal, HI_pp_dW_syst_window, iseta, false);
}