#include "mergeplot.h"
#include "CMS_lumi.C"
#include "tdrStyle.C"

void readfrankplot(TFile *f1, bool iseta, bool isbk, bool isppsub)
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
        g_frank_fit_dM = (TGraphErrors *)dir_fit->Get("graph_width_barrel_Zheng_fit");
        g_frank_fit_dW = (TGraphErrors *)dir_fit->Get("graph_width_barrel_Zheng_fit");
    }
    if (!iseta)
    {
        dir_rms = (TDirectoryFile *)f1->GetDirectory("WholeAcceptance/Graphs/RMS");
        dir_fit = (TDirectoryFile *)f1->GetDirectory("WholeAcceptance/Graphs/fit");
        g_frank_rms_dM = (TGraphErrors *)dir_rms->Get("graph_mean_WA_Zheng");
        g_frank_rms_dW = (TGraphErrors *)dir_rms->Get("graph_width_WA_Zheng");
        g_frank_fit_dM = (TGraphErrors *)dir_fit->Get("graph_width_WA_Zheng_fit");
        g_frank_fit_dW = (TGraphErrors *)dir_fit->Get("graph_width_WA_Zheng_fit");
    }
}
void readplot(TFile *f1, bool iseta, bool isbk)
{
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

    f1->cd();
    if (iseta)
    {
        if (isbk)
        {
            g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_eta_bksub");
            g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_eta_bksub");
            g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_eta_bksub");
            g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_eta_bksub");
        }
        if (!isbk)
        {
            g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_eta");
            g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_eta");
            g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_eta_nobksub");
            g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_eta_nobksub");
        }
    }
    if (!iseta)
    {
        if (isbk)
        {
            g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_raw_bksub");
            g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_raw_bksub");
            g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_raw_bksub");
            g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_raw_bksub");
        }
        if (!isbk)
        {
            g_zh_HI_dM = (TGraphErrors *)f1->Get("HI_dM_chi2_raw");
            g_zh_HI_dW = (TGraphErrors *)f1->Get("HI_dWidth_chi2_raw");
            g_zh_pp_dM = (TGraphErrors *)f1->Get("pp_dM_chi2_raw_nobksub");
            g_zh_pp_dW = (TGraphErrors *)f1->Get("pp_dWidth_chi2_raw_nobksub");
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

void changeorderfrank(TGraphErrors *g1, int shift)
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

void mergeplot(bool iseta = 1, bool isbk = 1, bool isppsub = 1)
{
    // one is pp + HI Points, without subtracting.
    // one is HI Points, with pp subtracted.
    setTDRStyle();

    // Frank's Place :)
    TFile *f_1 = new TFile("DiffPlots_RMS_Fits.root", "READ");
    readfrankplot(f_1, iseta, isbk, isppsub);

    // Zheng's Place :(

    TFile *f_2 = new TFile("../pp_18/All_plots.root", "READ");
    readplot(f_2, iseta, isbk);

    getppfit();
    changeorder(g_zh_HI_dM);
    changeorder(g_zh_HI_dW);
    changeorderfrank(g_frank_fit_dM, +1);
    changeorderfrank(g_frank_rms_dM, +1);

    subtractppfromHI(g_zh_HI_dM, fit_dm, fit_dm_err);
    subtractppfromHI(g_zh_HI_dW, fit_dw, fit_dw_err);

    TCanvas *c1 = new TCanvas("c1", "", 800, 800);
    c1->cd();

    g_zh_HI_dM->SetLineColor(kBlack);
    g_zh_HI_dM->SetMarkerColor(kBlack);
    g_zh_HI_dM->SetMarkerStyle(20); // Full circle
    g_zh_HI_dM->SetMarkerSize(1.2);
    g_zh_HI_dM->SetLineWidth(2);
    g_zh_HI_dM->GetYaxis()->SetRangeUser(-0.8, 0.8);
    g_zh_HI_dM->Draw("AP");

    g_frank_fit_dM->SetLineColor(kRed);
    g_frank_fit_dM->SetMarkerColor(kRed);
    g_frank_fit_dM->SetLineStyle(1);    // Solid line
    g_frank_fit_dM->SetMarkerStyle(21); // Full circle
    g_frank_fit_dM->SetMarkerSize(1.2);
    g_frank_fit_dM->SetLineWidth(3);
    g_frank_fit_dM->Draw("P SAME");

    g_frank_rms_dM->SetLineColor(kBlue);
    g_frank_rms_dM->SetMarkerColor(kBlue);
    g_frank_rms_dM->SetMarkerStyle(22); // Full circle
    g_frank_rms_dM->SetMarkerSize(1.2);
    g_frank_rms_dM->SetLineStyle(2);    // Dashed line
    g_frank_rms_dM->SetLineWidth(2);
    g_frank_rms_dM->Draw("P SAME");

    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(g_zh_HI_dM, "Template", "lp");
    legend->AddEntry(g_frank_fit_dM, "Fit", "lp");
    legend->AddEntry(g_frank_rms_dM, "RMS", "lp");
    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();

    CMS_lumi(c1,13,10);

    c1->SaveAs("test.png");
}