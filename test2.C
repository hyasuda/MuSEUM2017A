void test2( string filename = "scan_result.txt"){

    double pulse;
    double Vref2, Vref5;
    // const int count[2][4][128];
    int test[2][4][32];
    const int board = 2;
    const int cp    = 4;
    const int ch    = 32;

    ifstream ifs(filename, std::ios::in);

    ifs >> pulse >> Vref2 >> Vref5;

    for(int i = 0 ; i < board ; i++){
        for(int j = 0 ; j < cp ; j++){
            for(int k = 0 ; k < ch ; k++){
                ifs >> test[i][j][k];
            }
        }
    }

    cout << pulse << " " << Vref2 << " " << Vref5 << endl;

    for(int i = 0 ; i < board ; i++){
        for(int j = 0 ; j < cp ; j++){
            for(int k = 0 ; k < ch ; k++){
                cout << test[i][j][k] << endl;
            }
        }
    }

    // for(int i = 0 ; i < line ; i++){
    //     for(int j = 0 ; j < col ; j++){
    //         ifs >> test[i][j];
    //     }
    // }

    // for(int i = 0 ; i < line ; i++){
    //     for(int j = 0 ; j < col ; j++){
    //         cout << test[i][j] << endl;
    //     }
    // }


    return;
}
