void vref_scan( string filename = "scan_result.txt"){

    double pulse;
    double Vref2, Vref5;
    // const int count[2][4][128];
    int test[2][5];
    int line = 2;
    int col  = 5;

    ifstream ifs(filename, std::ios::in);

    // if(!ifs) cout << " file is not found ..." << endl;

    // while((ifs >> test)!=0){
    //     i++;
    // }
    //     for(int i=0 ; i++ ; i < 5){
    //     cout << test[i] << endl;
    // }

    // ifs >> test[0] >> test[1];
    // cout << test[0] << test[1] << endl;
    // while((ifs>>test)!=0){
    //     ifs >> test[i];
    //     i++;
    // }

    for(int i = 0 ; i < line ; i++){
        for(int j = 0 ; j < col ; j++){
            ifs >> test[i][j];
        }
    }

    for(int i = 0 ; i < line ; i++){
        for(int j = 0 ; j < col ; j++){
            cout << test[i][j] << endl;
        }
    }

    // for(int i=0; i<col ; i++ ){
    //     ifs >> test[i];
    // }

    // for(int i=0; i<5 ; i++){
    //     cout << test[i] << " " <<endl;
    // }


    return;
}
