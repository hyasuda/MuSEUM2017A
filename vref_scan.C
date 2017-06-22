void vref_scan( string filename = "scan_result.txt"){

    double pulse;
    double Vref2, Vref5;
    // const int count[2][4][128];
    int count[2][4][128];
    int sum[32][32];
    const int board =   2;
    const int cp    =   4;
    const int ch    = 128;
    const int div   =  128/32;
    const int part  = 32;

    cout << div << endl;

    ifstream ifs(filename, std::ios::in);

    TGraphErrors* gr = new TGraphErrors();

    ifs >> pulse >> Vref2 >> Vref5;

    for(int i = 0 ; i < board ; i++){
        for(int j = 0 ; j < cp ; j++){
            for(int k = 0 ; k < ch ; k++){
                ifs >> count[i][j][k];
            }
        }
    }

    ifs.close();

    // for(int i = 0 ; i < board ; i++){
    //     for(int j = 0 ; j < cp ; j++){
    //         for(int k = 0 ; k < div ; k++){
    //             for(int l = 0; l < part ; l++ ){

    //             }
    //         }
    //     }
    // }

    for(int i = 0 ; )
        for(int l = 0 ; l < div ; l++){
            for(int i = 0 ; i < part ; i++){
                count[k][j][i+32*l] >> sum[l+4*j+4*i];
            }
        }


    return;
}
