#include "mergeplot.h"
#include "CMS_lumi.C"
#include "tdrStyle.C"

void readfrankplot(TFile *f1, bool iseta, bool isbk, bool isppsub, bool isoriginalRMS = false)
{
    if (isppsub)
    {
        f1->cd();
        TDirectoryFile *dir_rms;
        TDirectoryFile *dir_fit;

        if (iseta)
        {
            dir_rms = (TDirectoryFile *)f1->GetDirectory("Barrel/Graphs/RMS");
            dir_fit = (TDirectoryFile *)f1->GetDirectory("Barrel/Graphs/fit");
            g_frank_rms_dM = (TGraphErrors *)dir_rms->Get("graph_mean_barrel_Zheng");
            g_frank_rms_dW = (TGraphErrors *)dir_rms->Get("graph_width_barrel_Zheng");
            g_frank_fit_dM = (TGraphErrors *)dir_fit->Get("graph_mean_barrel_Zheng_fit");
            g_frank_fit_dW = (TGraphErrors *)dir_fit->Get("graph_width_barrel_Zheng_fit");
        }
        if (!iseta)
        {
            dir_rms = (TDirectoryFile *)f1->GetDirectory("WholeAcceptance/Graphs/RMS");
            dir_fit = (TDirectoryFile *)f1->GetDirectory("WholeAcceptance/Graphs/fit");
            g_frank_rms_dM = (TGraphErrors *)dir_rms->Get("graph_mean_WA_Zheng");
            g_frank_rms_dW = (TGraphErrors *)dir_rms->Get("graph_width_WA_Zheng");
            g_frank_fit_dM = (TGraphErrors *)dir_fit->Get("graph_mean_WA_Zheng_fit");
            g_frank_fit_dW = (TGraphErrors *)dir_fit->Get("graph_width_WA_Zheng_fit");
        }
    }
    if (!isppsub)
    {
        if (!isoriginalRMS)
        {
            f1->cd();
            TDirectoryFile *dir_fit;
            dir_fit = (TDirectoryFile *)f1->GetDirectory("GraphsValues");
            g_frank_fit_dM = (TGraphErrors *)dir_fit->Get("massValGraphNewCent");
            g_frank_fit_dW = (TGraphErrors *)dir_fit->Get("widthValGraphNewCent");

            TDirectoryFile *dir_canvas;
            dir_canvas = (TDirectoryFile *)f1->GetDirectory("Canvases");
            c_frank_fit_dM = (TCanvas *)dir_canvas->Get("cMassValNewCent");
            c_frank_fit_dW = (TCanvas *)dir_canvas->Get("cWidthValNewCent");

            h_frank_fit_pp_dM = (TH1D *)c_frank_fit_dM->GetListOfPrimitives()->FindObject("HistMassValppNewCent_dummyHist");
            h_frank_fit_pp_dW = (TH1D *)c_frank_fit_dW->GetListOfPrimitives()->FindObject("HistWidthValppNewCent_dummyHist");
        }
        if (isoriginalRMS)
        {
            f1->cd();
            if (iseta)
            {
                TDirectoryFile *dir_rms;
                dir_rms = (TDirectoryFile *)f1->GetDirectory("GraphsValues/Barrel");
                g_frank_rms_dM = (TGraphErrors *)dir_rms->Get("massValGraph_barrel");
                g_frank_rms_dW = (TGraphErrors *)dir_rms->Get("widthValGraph_barrel");

                TDirectoryFile *dir_canvas;
                dir_canvas = (TDirectoryFile *)f1->GetDirectory("Canvases/Values/Barrel");
                c_frank_rms_dM = (TCanvas *)dir_canvas->Get("cMassVal_barrel_NewCent");
                c_frank_rms_dW = (TCanvas *)dir_canvas->Get("cWidthVal_barrel_NewCent");

                h_frank_rms_pp_dM = (TH1D *)c_frank_rms_dM->GetListOfPrimitives()->FindObject("HistMassValpp_barrel_NewCent_dummyHist");
                h_frank_rms_pp_dW = (TH1D *)c_frank_rms_dW->GetListOfPrimitives()->FindObject("HistWidthValpp_barrel_NewCent_dummyHist");
            }
            if (!iseta)
            {
                TDirectoryFile *dir_rms;
                dir_rms = (TDirectoryFile *)f1->GetDirectory("GraphsValues/WholeAcceptance");
                g_frank_rms_dM = (TGraphErrors *)dir_rms->Get("massValGraph_WA");
                g_frank_rms_dW = (TGraphErrors *)dir_rms->Get("widthValGraph_WA");

                TDirectoryFile *dir_canvas;
                dir_canvas = (TDirectoryFile *)f1->GetDirectory("Canvases/Values/WholeAcceptance");
                c_frank_rms_dM = (TCanvas *)dir_canvas->Get("cMassVal_WA_NewCent");
                c_frank_rms_dW = (TCanvas *)dir_canvas->Get("cWidthVal_WA_NewCent");

                h_frank_rms_pp_dM = (TH1D *)c_frank_rms_dM->GetListOfPrimitives()->FindObject("HistMassValpp_WA_NewCent_dummyHist");
                h_frank_rms_pp_dW = (TH1D *)c_frank_rms_dW->GetListOfPrimitives()->FindObject("HistWidthValpp_WA_NewCent_dummyHist");
            }
        }
    }
}
void readplot(TFile *f1, bool iseta, bool isbk, bool iseff)
{
    // PP now is special, it is data without eff, with/without special PbPb background (without eff), with mc signal with eff correction
    //  Naming:
    /*
    nothing:
    HI_dM_chi2_raw
    HI_dWidth_chi2_raw
    HI_dM_chi2_eta
    HI_dWidth_chi2_eta

    bksub:
    HI_dM_chi2_raw_bksub
    HI_dWidth_chi2_raw_bksub
    HI_dM_chi2_eta_bksub
    HI_dWidth_chi2_eta_bksub

    eff:
    HI_dM_chi2_raw_eff
    HI_dWidth_chi2_raw_eff
    HI_dM_chi2_eta_eff
    HI_dWidth_chi2_eta_eff

    bk+eff:
    HI_dM_chi2_raw_bksub_eff
    HI_dWidth_chi2_raw_bksub_eff
    HI_dM_chi2_eta_bksub_eff
    HI_dWidth_chi2_eta_bksub_eff
    */

    // For pp:
    /* bksub:
    pp_dM_chi2_raw_bksub
    pp_dWidth_chi2_raw_bksub
    pp_dM_chi2_eta_bksub
    pp_dWidth_chi2_eta_bksub

    nobksub:
    pp_dM_chi2_raw_nobksub
    pp_dWidth_chi2_raw_nobksub
    pp_dM_chi2_eta_nobksub
    pp_dWidth_chi2_eta_nobksub
    */

    f1->cd();
    if (iseta)
    {
        if (isbk)
        {
            if (iseff)
            {
                // eta, bk, eff
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_eta_bksub_eff");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_eta_bksub_eff");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_eta_bksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_eta_bksub");
            }
            if (!iseff)
            {
                // eta, bk
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_eta_bksub");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_eta_bksub");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_eta_bksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_eta_bksub");
            }
        }
        if (!isbk)
        {
            if (iseff)
            {
                // eta, eff
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_eta_eff");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_eta_eff");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_eta_nobksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_eta_nobksub");
            }
            if (!iseff)
            {
                // eta
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_eta");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_eta");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_eta_nobksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_eta_nobksub");
            }
        }
    }
    if (!iseta)
    {
        if (isbk)
        {
            if (iseff)
            {
                // raw, bk, eff
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_raw_bksub_eff");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_raw_bksub_eff");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_raw_bksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_raw_bksub");
            }
            if (!iseff)
            {
                // raw, bk
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_raw_bksub");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_raw_bksub");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_raw_bksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_raw_bksub");
            }
        }
        if (!isbk)
        {
            if (iseff)
            {
                // raw,eff
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_raw_eff");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_raw_eff");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_raw_nobksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_raw_nobksub");
            }
            if (!iseff)
            {
                // raw
                g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_raw");
                g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_raw");
                g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_raw_nobksub");
                g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_raw_nobksub");
            }
        }
    }
}

void getppfit()
{
    TF1 *fit_pp_chi_dm = new TF1("fit_pp_template_dm", "[0]", 0, 22.5);
    TF1 *fit_pp_chi_dw = new TF1("fit_pp_template_dw", "[0]", 0, 22.5);
    g_zh_pp_dM->Fit(fit_pp_chi_dm, "QR", "", 0.5, 22.5);
    g_zh_pp_dW->Fit(fit_pp_chi_dw, "QR", "", 0.5, 22.5);

    fit_dm = fit_pp_chi_dm->GetParameter(0);
    fit_dm_err = fit_pp_chi_dm->GetParError(0);

    fit_dw = fit_pp_chi_dw->GetParameter(0);
    fit_dw_err = fit_pp_chi_dw->GetParError(0);

    cout << "DM is " << fit_dm << " +- " << fit_dm_err << endl;
    cout << "DW is " << fit_dw << " +- " << fit_dw_err << endl;
}

void changeorder(TGraphErrors *g1)
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
    std::cout << "Original Points:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
        std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;
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
    std::cout << "\nUpdated Points:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
        std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;
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

    std::cout << "Before Shift:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y); // Get current x and y
        ex = g1->GetErrorX(i); // Get x error
        ey = g1->GetErrorY(i); // Get y error

        std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;

        // Shift the x value
        x += shift;

        // Update the graph
        g1->SetPoint(i, x, y);
        g1->SetPointError(i, ex, ey); // Errors remain unchanged
    }

    std::cout << "\nAfter Shift:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y); // Get updated x and y
        ex = g1->GetErrorX(i); // Get x error
        ey = g1->GetErrorY(i); // Get y error

        std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;
    }
}

void subtractppfromHI(TGraphErrors *g1, double value, double valueErr)
{
    int n = g1->GetN(); // Number of points in the graph

    // Temporary arrays to store updated y-values and errors
    double x, y, ex, ey;

    std::cout << "Before Subtraction:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y); // Get the x and y values
        ex = g1->GetErrorX(i); // Get x error
        ey = g1->GetErrorY(i); // Get y error

        std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;

        // Subtract the value and propagate the error
        y -= value;                                    // Subtract the constant value
        ey = std::sqrt(ey * ey + valueErr * valueErr); // Combine errors quadratically

        // Update the graph
        g1->SetPoint(i, x, y);
        g1->SetPointError(i, ex, ey);
    }

    std::cout << "\nAfter Subtraction:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x, y);
        ex = g1->GetErrorX(i);
        ey = g1->GetErrorY(i);
        std::cout << "Point " << i << ": x = " << x << ", y = " << y
                  << ", ex = " << ex << ", ey = " << ey << std::endl;
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
    std::cout << "Original Points:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
        std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;
    }

    x[n] = n + 1;
    ex[n] = 0;
    y[n] = value;
    ey[n] = valueErr;

    g1 = new TGraphErrors(n + 1, x, y, ex, ey);

    cout << "# of points is" << g1->GetN() << endl;

    // Print updated points
    std::cout << "\nUpdated Points:" << std::endl;
    for (int i = 0; i < n + 1; ++i)
    {
        g1->GetPoint(i, x[i], y[i]);
        ex[i] = g1->GetErrorX(i);
        ey[i] = g1->GetErrorY(i);
        std::cout << "x[" << i << "] = " << x[i] << ", y[" << i << "] = " << y[i]
                  << ", ex[" << i << "] = " << ex[i] << ", ey[" << i << "] = " << ey[i] << std::endl;
    }

    // Clean up temporary arrays
    delete[] x;
    delete[] y;
    delete[] ex;
    delete[] ey;

    return g1;
}

void drawsubtractionplot(TCanvas *c1, TGraphErrors *g1, TGraphErrors *g2, TGraphErrors *g3, bool iseta, bool isdM, bool isbk, bool iseff)
{

    TString savingname;
    if (iseta)
    {
        if (iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/eta_dM_eff_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/eta_dW_eff_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/eta_dM_eff.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/eta_dW_eff.png";
                }
            }
        }
        if (!iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/eta_dM_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/eta_dW_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/eta_dM.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/eta_dW.png";
                }
            }
        }
    }
    if (!iseta)
    {
        if (iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/raw_dM_eff_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/raw_dW_eff_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/raw_dM_eff.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/raw_dW_eff.png";
                }
            }
        }
        if (!iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/raw_dM_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/raw_dW_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HI-pp/raw_dM.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HI-pp/raw_dW.png";
                }
            }
        }
    }

    c1->cd();
    if (isdM)
        g1->GetYaxis()->SetTitle("#DeltaM (GeV)");
    if (!isdM)
        g1->GetYaxis()->SetTitle("#DeltaWidth (GeV)");
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

    g3->SetLineColor(kBlue);
    g3->SetMarkerColor(kBlue);
    g3->SetMarkerStyle(24); // Full circle
    g3->SetMarkerSize(1.2);
    g3->SetLineStyle(1); // Dashed line
    g3->SetLineWidth(2);
    g3->Draw("P SAME");

    TLegend *legend = new TLegend(0.55, 0.7, 0.9, 0.9);
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
        if (isbk)
        {
            latex.DrawLatex(1.0, 0.45, "|#eta| < 1");
            // latex.DrawLatex(1.0, 0.35, "temp bk sub");
        }
        if (!isbk)
        {
            latex.DrawLatex(1.0, 0.45, "|#eta| < 1");
            // latex.DrawLatex(1.0, 0.35, "temp no bk sub");
        }
    }
    if (!iseta)
    {
        if (isbk)
        {
            latex.DrawLatex(1.0, 0.45, "|#eta| < 2.4");
            // latex.DrawLatex(1.0, 0.35, "temp bk sub");
        }
        if (!isbk)
        {
            latex.DrawLatex(1.0, 0.45, "|#eta| < 2.4");
            // latex.DrawLatex(1.0, 0.35, "temp no bk sub");
        }
    }

    CMS_lumi(c1, 13, 10);

    c1->SaveAs(savingname);
}

void drawHIppplot(TCanvas *c1 = nullptr, TGraphErrors *g1 = nullptr, TGraphErrors *g2 = nullptr, TGraphErrors *g3 = nullptr, bool iseta = false, bool isdM = false, bool isbk = false, bool iseff = false)
{
    TString savingname;
    if (iseta)
    {
        if (iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/eta_dM_eff_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/eta_dW_eff_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/eta_dM_eff.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/eta_dW_eff.png";
                }
            }
        }
        if (!iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/eta_dM_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/eta_dW_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/eta_dM.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/eta_dW.png";
                }
            }
        }
    }
    if (!iseta)
    {
        if (iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/raw_dM_eff_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/raw_dW_eff_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/raw_dM_eff.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/raw_dW_eff.png";
                }
            }
        }
        if (!iseff)
        {
            if (isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/raw_dM_bk.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/raw_dW_bk.png";
                }
            }
            if (!isbk)
            {
                if (isdM)
                {
                    savingname = "./plots/HIandpp/raw_dM.png";
                }
                if (!isdM)
                {
                    savingname = "./plots/HIandpp/raw_dW.png";
                }
            }
        }
    }

    c1->cd();
    if (isdM)
        g1->GetYaxis()->SetTitle("M (GeV)");
    if (!isdM)
        g1->GetYaxis()->SetTitle("Width (GeV)");
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

    g2->SetLineColor(kRed);
    g2->SetMarkerColor(kRed);
    g2->SetLineStyle(1);    // Solid line
    g2->SetMarkerStyle(21); // Full circle
    g2->SetMarkerSize(1.2);
    g2->SetLineWidth(3);
    g2->Draw("P SAME");

    g3->SetLineColor(kBlue);
    g3->SetMarkerColor(kBlue);
    g3->SetMarkerStyle(24); // Full circle
    g3->SetMarkerSize(1.2);
    g3->SetLineStyle(1); // Dashed line
    g3->SetLineWidth(2);
    g3->Draw("P SAME");

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

    TLegend *legend = new TLegend(0.55, 0.7, 0.9, 0.9);
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
        if (isbk)
        {
            if (isdM)
                latex.DrawLatex(1.0, 91.7, "|#eta| < 1");
            if (!isdM)
                latex.DrawLatex(1.0, 4.5, "|#eta| < 1");
            // latex.DrawLatex(1.0, 0.35, "temp bk sub");
        }
        if (!isbk)
        {
            if (isdM)
                latex.DrawLatex(1.0, 91.7, "|#eta| < 1");
            if (!isdM)
                latex.DrawLatex(1.0, 4.5, "|#eta| < 1");
            // latex.DrawLatex(1.0, 0.35, "temp no bk sub");
        }
    }
    if (!iseta)
    {
        if (isbk)
        {
            if (isdM)
                latex.DrawLatex(1.0, 91.7, "|#eta| < 2.4");
            if (!isdM)
                latex.DrawLatex(1.0, 4.5, "|#eta| < 2.4");
            // latex.DrawLatex(1.0, 0.35, "temp bk sub");
        }
        if (!isbk)
        {
            if (isdM)
                latex.DrawLatex(1.0, 91.7, "|#eta| < 2.4");
            if (!isdM)
                latex.DrawLatex(1.0, 4.5, "|#eta| < 2.4");
            // latex.DrawLatex(1.0, 0.35, "temp no bk sub");
        }
    }

    CMS_lumi(c1, 13, 10);

    c1->SaveAs(savingname);
}

void mergeplot(bool iseta = 0, bool isbk = 1, bool iseff = 1,bool isppsub = 0)
{
    // one is pp + HI Points, without subtracting.
    // one is HI Points, with pp subtracted.
    setTDRStyle();

    if (isppsub)
    {
        // Frank's Place :)
        TFile *f_1 = new TFile("DiffPlots_RMS_Fits.root", "READ");
        readfrankplot(f_1, iseta, isbk, isppsub);

        // Zheng's Place :(

        TFile *f_2 = new TFile("All_plots.root", "READ");
        readplot(f_2, iseta, isbk, iseff);

        getppfit();
        cout << "Now Changing Order of dM" << endl;
        changeorder(g_zh_HI_dM);
        cout << "Now Changing Order of dW" << endl;
        changeorder(g_zh_HI_dW);

        changeorderfrank(g_frank_fit_dM, +1);
        changeorderfrank(g_frank_rms_dM, +1);
        changeorderfrank(g_frank_fit_dW, +1);
        changeorderfrank(g_frank_rms_dW, +1);

        // To shift the points a little bit
        changeorderfrank(g_zh_HI_dM, -0.1);
        // changeorderfrank(g_frank_fit_dM)
        changeorderfrank(g_frank_rms_dM, +0.1);
        changeorderfrank(g_zh_HI_dW, -0.1);
        // changeorderfrank(g_frank_fit_dM)
        changeorderfrank(g_frank_rms_dW, +0.1);

        cout << "Now Doing HI - PP of dM" << endl;
        subtractppfromHI(g_zh_HI_dM, fit_dm, fit_dm_err);
        cout << "Now Doing HI - PP of dW" << endl;
        subtractppfromHI(g_zh_HI_dW, fit_dw, fit_dw_err);

        TCanvas *c1 = new TCanvas("c1", "", 800, 800);
        TCanvas *c2 = new TCanvas("c2", "", 800, 800);
        drawsubtractionplot(c1, g_zh_HI_dM, g_frank_fit_dM, g_frank_rms_dM, iseta, true, isbk, iseff);
        drawsubtractionplot(c2, g_zh_HI_dW, g_frank_fit_dW, g_frank_rms_dW, iseta, false, isbk, iseff);
    }

    if (!isppsub)
    {
        TFile *f_1;
        // Frank's Place :)

        if (iseta)
        {
            f_1 = new TFile("PbPbCentDiff_Barrel3v3.root", "READ");
        }
        if (!iseta)
        {
            f_1 = new TFile("PbPbCentDiff_WA3v3.root", "READ");
        }

        TFile *f_3 = new TFile("ppPbPbCentMeanRMS_bkgd_subtracted.root", "READ");

        readfrankplot(f_1, iseta, isbk, isppsub, false);
        readfrankplot(f_3, iseta, isbk, isppsub, true);

        // Zheng's Place :(

        TFile *f_2 = new TFile("All_plots.root", "READ");
        readplot(f_2, iseta, isbk, iseff);

        changeorder(g_zh_HI_dM);
        changeorder(g_zh_HI_dW);
        subtractppfromHI(g_zh_HI_dM, -91.1876, 0);
        subtractppfromHI(g_zh_HI_dW, -2.4955, 0);
        subtractppfromHI(g_zh_pp_dM, -91.1876, 0);
        subtractppfromHI(g_zh_pp_dW, -2.4955, 0);

        getppfit();

        changeorderfrank(g_frank_fit_dM, +1);
        changeorderfrank(g_frank_fit_dW, +1);
        changeorderfrank(g_frank_rms_dM, 0);
        changeorderfrank(g_frank_rms_dW, 0);

        double frank_fit_pp_dM = h_frank_fit_pp_dM->GetBinContent(1);
        double frank_fit_pp_dM_err = h_frank_fit_pp_dM->GetBinError(1);
        double frank_fit_pp_dW = h_frank_fit_pp_dW->GetBinContent(1);
        double frank_fit_pp_dW_err = h_frank_fit_pp_dW->GetBinError(1);

        double frank_rms_pp_dM = h_frank_rms_pp_dM->GetBinContent(1);
        double frank_rms_pp_dM_err = h_frank_rms_pp_dM->GetBinError(1);
        double frank_rms_pp_dW = h_frank_rms_pp_dW->GetBinContent(1);
        double frank_rms_pp_dW_err = h_frank_rms_pp_dW->GetBinError(1);

        g_frank_fit_dM = addpppoint(g_frank_fit_dM, frank_fit_pp_dM, frank_fit_pp_dM_err);
        g_frank_fit_dW = addpppoint(g_frank_fit_dW, frank_fit_pp_dW, frank_fit_pp_dW_err);
        g_frank_rms_dM = addpppoint(g_frank_rms_dM, frank_rms_pp_dM, frank_rms_pp_dM_err);
        g_frank_rms_dW = addpppoint(g_frank_rms_dW, frank_rms_pp_dW, frank_rms_pp_dW_err);

        g_zh_HI_dM = addpppoint(g_zh_HI_dM, fit_dm, fit_dm_err);
        g_zh_HI_dW = addpppoint(g_zh_HI_dW, fit_dw, fit_dw_err);

        TCanvas *c1 = new TCanvas("c1", "", 800, 800);
        TCanvas *c2 = new TCanvas("c2", "", 800, 800);

        drawHIppplot(c1, g_zh_HI_dM, g_frank_fit_dM, g_frank_rms_dM, iseta, true, isbk, iseff);
        drawHIppplot(c2, g_zh_HI_dW, g_frank_fit_dW, g_frank_rms_dW, iseta, false, isbk, iseff);
    }
}