double std_dev(std::vector<double> a) {
    if(a.size() == 0)
        return 0.0;
    double sum = 0;
    for(int i = 0; i < a.size(); ++i)
       sum += a[i];
    double mean = sum / a.size();
    double sq_diff_sum = 0;
    for(int i = 0; i < a.size(); ++i) {
       double diff = a[i] - mean;
       sq_diff_sum += diff * diff;
    }
    double variance = sq_diff_sum / a.size();
    return sqrt(variance);
}

double avg(std::vector<double> a) {
    if(a.size() == 0)
        return 0.0;
    double sum = 0;
    for(int i = 0; i < a.size(); ++i)
       sum += a[i];
    return sum/(a.size()-1);
}
