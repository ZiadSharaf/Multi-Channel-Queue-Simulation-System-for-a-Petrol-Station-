#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <queue>
#include <fstream>
using namespace std;

//Define the car class to represent the behaviors of each car in the simulation.
class car
{
private:
    int car_number;                  //Unique identifier for the car
    char car_category;               //Category of the car
    int time_between_arrivals;       //Time interval between arrivals of cars
    int arrival_time;                //Time at which the car arrives
    int service_time;                //Duration of the car's service
    int leave_time;                  //Time when car leaves
    int service_start_95_octane;     //Start time of service at 95 Octane pump
    int service_start_90_octane;     //Start time of service at 90 Octane pump
    int service_start_gas;           //Start time of service at Gas pump
    int idle_time_95;                //Idle time for the 95 Octane pump
    int idle_time_90;                //Idle time for the 90 Octane pump
    int idle_time_gas;               //Idle time for the Gas pump
    string fuel_type;                //Type of fuel used by the car
    int service_start_gas_2;         //Start time at the second Gas pump
    int idle_time_gas_2;             //Idle time for the second Gas pump
    int service_start_90_octane_2;   //Start time at the second 90 Octane pump
    int idle_time_90_octane_2;       //Idle time for the second 90 Octane pump
    int service_start_95_octane_2;   //Start time at the second 95 Octane pump
    int idle_time_95_octane_2;       //Idle time for the second 95 Octane pump

public:
    //Setters to update the attributes
    void set_car_number(int car_number)
    {
        this->car_number=car_number;
    }
    void set_car_category(char car_category)
    {
        this->car_category=car_category;
    }
    void set_time_between_arrivals(int time_between_arrivals)
    {
        this->time_between_arrivals=time_between_arrivals;
    }
    void set_arrival_time(int arrival_time)
    {
        this->arrival_time=arrival_time;
    }
    void set_service_time(int service_time)
    {
        this->service_time=service_time;
    }
    void set_leave_time(int leave_time)
    {
        this->leave_time=leave_time;
    }
    void set_idle_time_95(int idle_time_95)
    {
        this->idle_time_95=idle_time_95;
    }
    void set_idle_time_90(int idle_time_90)
    {
        this->idle_time_90=idle_time_90;
    }
    void set_idle_time_gas(int idle_time_gas)
    {
        this->idle_time_gas=idle_time_gas;
    }
    void set_fuel_type(string fuel_type)
    {
        this->fuel_type=fuel_type;
    }
    void set_service_start_95_octane(int service_start_95_octane)
    {
        this->service_start_95_octane=service_start_95_octane;
    }
    void set_service_start_90_octane(int service_start_90_octane)
    {
        this->service_start_90_octane=service_start_90_octane;
    }
    void set_service_start_gas(int service_start_gas)
    {
        this->service_start_gas=service_start_gas;
    }
    void set_service_start_gas_2(int service_start_gas_2)
    {
        this->service_start_gas_2=service_start_gas_2;
    }
    void set_idle_time_gas_2(int idle_time_gas_2)
    {
        this->idle_time_gas_2=idle_time_gas_2;
    }
    void set_service_start_90_octane_2(int service_start_90_octane_2)
    {
        this->service_start_90_octane_2=service_start_90_octane_2;
    }
    void set_idle_time_90_octane_2(int idle_time_90_octane_2)
    {
        this->idle_time_90_octane_2=idle_time_90_octane_2;
    }
    void set_service_start_95_octane_2(int service_start_95_octane_2)
    {
        this->service_start_95_octane_2=service_start_95_octane_2;
    }
    void set_idle_time_95_octane_2(int idle_time_95_octane_2)
    {
        this->idle_time_95_octane_2=idle_time_95_octane_2;
    }


    //Getters to retrieve the attributes of a car
    int get_car_number()
    {
        return car_number;
    }
    char get_car_category()
    {
        return car_category;
    }
    int get_time_between_arrivals()
    {
        return time_between_arrivals;
    }
    int get_arrival_time()
    {
        return arrival_time;
    }
    int get_service_time()
    {
        return service_time;
    }
    int get_leave_time()
    {
        return leave_time;
    }
    string get_fuel_type()
    {
        return fuel_type;
    }
    int get_idle_time_95()
    {
        return idle_time_95;
    }
    int get_idle_time_90()
    {
        return idle_time_90;
    }
    int get_idle_time_gas()
    {
        return idle_time_gas;
    }
    int get_service_start_95_octane()
    {
        return service_start_95_octane;
    }
    int get_service_start_90_octane()
    {
        return service_start_90_octane;
    }
    int get_service_start_gas()
    {
        return service_start_gas;
    }
    int get_service_start_gas_2()
    {
        return service_start_gas_2;
    }
    int get_idle_time_gas_2()
    {
        return idle_time_gas_2;
    }
    int get_service_start_90_octane_2()
    {
        return service_start_90_octane_2;
    }
    int get_idle_time_90_octane_2()
    {
        return idle_time_90_octane_2;
    }
    int get_service_start_95_octane_2()
    {
        return service_start_95_octane_2;
    }
    int get_idle_time_95_octane_2()
    {
        return idle_time_95_octane_2;
    }
};

//Generate random car category based on probability ranges
char generate_car_category(float prob_a,float prob_b,float prob_c)
{

    //Generate a random number [0.01,1]
    float random_number=(float)(rand()%100)/100+0.01;

    //Determine the category based on the random number
    if (random_number<=prob_a)
    {
        return 'A';
    }
    else if (random_number<=prob_a+prob_b)
    {
        return 'B';
    }
    else
    {
        return 'C';
    }
}

//Generate random time between arrivals based on probability ranges
int generate_time_between_arrivals(int* values,float* probabilities,int num_ranges)
{

    //Generate a random number [0.01,1]
    float random_number=(float)(rand()%100)/100+0.01;
    float cumulative_probability=0;

    // Determine the time between arrivals
    for (int i=0;i<num_ranges;i++)
    {
        cumulative_probability+=probabilities[i];
        if (random_number<=cumulative_probability)
        {
            return values[i];
        }
    }
    return -1;
}

//Generate random service time for categories A and B based on probability ranges
int generate_service_time_for_category_a_b(int* values,float* probabilities,int num_ranges)
{
    //Generate a random number [0.01,1]
    float random_number=(float)(rand()%100)/100+0.01;
    float cumulative_probability=0;

    // Determine the time between arrivals
    for (int i=0;i<num_ranges;i++)
    {
        cumulative_probability+=probabilities[i];
        if (random_number<=cumulative_probability)
        {
            return values[i];
        }
    }
    return -1;
}

//Generate random service time for categories C based on probability ranges
int generate_service_time_for_category_c(int* values,float* probabilities,int num_ranges)
{
    //Generate a random number [0.01,1]
    float random_number=(float)(rand()%100)/100+0.01;
    float cumulative_probability=0;

    // Determine the time between arrivals
    for (int i=0;i<num_ranges;i++)
    {
        cumulative_probability+=probabilities[i];
        if (random_number<=cumulative_probability)
        {
            return values[i];
        }
    }
    return -1;
}


//Function to write results to CSV file
void write_to_csv(const string& filename, int num_of_runs,float* avg_service_category_a,float* avg_service_category_b,float* avg_service_category_c,float* avg_service_95,float* avg_service_90,float* avg_service_gas,
                  float* avg_wait_95, float* avg_wait_90,float* avg_wait_gas,float* avg_wait_all,
                  int* max_queue_95,int* max_queue_90,int* max_queue_gas,float* avg_prob_wait_95,float* avg_prob_wait_90,float* avg_prob_wait_gas,float* avg_prob_idle_95,float* avg_prob_idle_90,float* avg_prob_idle_gas)
{
    //Check if the file was opened or not
    ofstream csv_file(filename);
    if (!csv_file.is_open())
    {
        cerr<<"Error: Unable to open file "<<filename<<endl;
        return;
    }

    //Write the header
    csv_file<<"Run,Avg Service Time Category A,Avg Service Time Category B,Avg Service Time Category C,";
    csv_file<<"Avg Service Time 95,Avg Service Time 90,Avg Service Time Gas,";
    csv_file<<"Avg Wait Time 95,Avg Wait Time 90,Avg Wait Time Gas,Avg Wait Time All Cars,";
    csv_file<<"Avg Max Queue Length 95,Avg Max Queue Length 90,Avg Max Queue Length Gas,";
    csv_file<<"Avg prob. wait 95,Avg prob. wait 90,Avg prob. wait Gas,";
    csv_file<<"Avg prob. idle 95,Avg prob. idle 90,Avg prob. idle Gas"<<endl;

    //Write the data for each run
    for (int i=0;i<num_of_runs;i++)
    {
        csv_file<<i+1<<",";
        csv_file<<avg_service_category_a[i]<<","<<avg_service_category_b[i]<<","<<avg_service_category_c[i]<<",";
        csv_file<<avg_service_95[i]<<","<<avg_service_90[i]<<","<<avg_service_gas[i]<<",";
        csv_file<<avg_wait_95[i]<<","<<avg_wait_90[i]<<","<<avg_wait_gas[i]<<",";
        csv_file<<avg_wait_all[i]<< ",";
        csv_file<<max_queue_95[i]<<","<<max_queue_90[i]<<","<<max_queue_gas[i]<<",";
        csv_file<<avg_prob_wait_95[i]<<","<<avg_prob_wait_90[i]<<","<<avg_prob_wait_gas[i]<<",";
        csv_file<<avg_prob_idle_95[i]<<","<<avg_prob_idle_90[i]<<","<<avg_prob_idle_gas[i]<<endl;
    }
    csv_file.close();
}

int main()
{
    srand((time(0)));   //Seed the random number generator with the current time for randomization.


    //Input probabilities for category A, B, C
    float prob_a, prob_b, prob_c;

    cout<<"=========================="<<endl;
    cout<<" Car Category Probability"<<endl;
    cout<<"=========================="<<endl;

    cout<<"Enter probabilities for each category (A, B, C):"<<endl;
    do
    {
        cout<<"  Probability for A (0 to 1): ";
        cin>>prob_a;

        if (prob_a==-1||prob_a<0||prob_a>1)
        {
            cerr<<"  Invalid input for A. Please enter a value between 0 and 1."<<endl;
            continue;
        }

        cout<<"  Probability for B (0 to 1): ";
        cin>>prob_b;

        if (prob_b==-1||prob_b<0||prob_b>1)
        {
            cerr<<"  Invalid input for B. Please enter a value between 0 and 1."<<endl;
            continue;
        }

        cout<<"  Probability for C (0 to 1): ";
        cin>>prob_c;

        if (prob_c==-1||prob_c<0||prob_c>1)
        {
            cerr<<"  Invalid input for C. Please enter a value between 0 and 1."<<endl;
            continue;
        }

        if ((prob_a + prob_b + prob_c)!=1)
        {
            cerr<<"\nError: Probabilities must sum to 1. Please try again."<<endl;
        }
        else
        {
            break;
        }
    } while (true);
    cout<<endl;


    //Input the number of ranges for time between arrivals
    cout<<"=================================="<<endl;
    cout<<" Time Between Arrivals Probability"<<endl;
    cout<<"=================================="<<endl;

    int num_ranges_time_between_arrivals;
    cout<<"Enter the number of ranges: ";
    cin>>num_ranges_time_between_arrivals;


    int* values_time_between_arrivals=new int[num_ranges_time_between_arrivals];
    float* probabilities_time_between_arrivals=new float[num_ranges_time_between_arrivals];
    bool flag_1=false;

    do {
        float total_probability=0;
        flag_1=true;

        cout<<"\nEnter each range value and its probability:"<<endl;
        for (int i=0;i<num_ranges_time_between_arrivals;i++)
            {
            cout<<"  Range value "<<i+1<<": ";
            cin>>values_time_between_arrivals[i];
            cout<<"  Probability for value "<<values_time_between_arrivals[i]<<" (0 to 1): ";
            cin>>probabilities_time_between_arrivals[i];

            if (probabilities_time_between_arrivals[i]<0||probabilities_time_between_arrivals[i]>1)
            {
                cerr<<"  Invalid input for probability. Please enter a value between 0 and 1."<<endl;
                flag_1=false;
                break;
            }

            total_probability+=probabilities_time_between_arrivals[i];
        }

        if (flag_1&&total_probability!=1)
        {
            cerr<<"\nError: Probabilities must sum to 1. Please try again."<<endl;
            flag_1=false;
        }

    } while (!flag_1);
    cout<<endl;

    //Input the number of ranges for Category A & B Service Time
    cout<<"========================================"<<endl;
    cout<<" Category A & B Service Time Probability"<<endl;
    cout<<"========================================"<<endl;

    int num_ranges_category_a_b_service_time;
    cout<<"Enter the number of ranges: ";
    cin>>num_ranges_category_a_b_service_time;


    int* values_category_a_b_service_time=new int[num_ranges_category_a_b_service_time];
    float* probabilities_category_a_b_service_time=new float[num_ranges_category_a_b_service_time];
    bool flag_2=false;

    do {
        float total_probability=0;
        flag_2=true;

        cout<<"\nEnter each range value and its probability:"<<endl;
        for (int i=0;i<num_ranges_category_a_b_service_time;i++)
            {
            cout<<"  Range value " << i + 1 << ": ";
            cin>>values_category_a_b_service_time[i];
            cout<<"  Probability for value " << values_category_a_b_service_time[i]<<" (0 to 1): ";
            cin>>probabilities_category_a_b_service_time[i];

            if (probabilities_category_a_b_service_time[i]<0||probabilities_category_a_b_service_time[i]>1)
            {
                cerr<<"  Invalid input for probability. Please enter a value between 0 and 1."<<endl;
                flag_2=false;
                break;
            }

            total_probability+=probabilities_category_a_b_service_time[i];
        }

        if (flag_2&&total_probability!=1)
        {
            cerr<<"\nError: Probabilities must sum to 1. Please try again.\n";
            flag_2=false;
        }

    } while (!flag_2);
    cout<<endl;

    //Input the number of ranges for Category C Service Time
    cout<<"========================================"<<endl;
    cout<<" Category C Service Time Probability"<<endl;
    cout<<"========================================"<<endl;

    int num_ranges_category_c_service_time;
    cout<<"Enter the number of ranges: ";
    cin>>num_ranges_category_c_service_time;


    int* values_category_c_service_time=new int[num_ranges_category_c_service_time];
    float* probabilities_category_c_service_time=new float[num_ranges_category_c_service_time];
    bool flag_3=false;

    do {
        float total_probability = 0;
        flag_3=true;

        cout<<"\nEnter each range value and its probability:"<<endl;
        for (int i=0;i<num_ranges_category_c_service_time;i++)
            {
            cout<<"  Range value " << i + 1 << ": ";
            cin>>values_category_c_service_time[i];
            cout<<"  Probability for value " << values_category_c_service_time[i] << " (0 to 1): ";
            cin>>probabilities_category_c_service_time[i];

            if (probabilities_category_c_service_time[i]<0||probabilities_category_c_service_time[i]>1)
            {
                cerr<< "  Invalid input for probability. Please enter a value between 0 and 1."<<endl;
                flag_3=false;
                break;
            }

            total_probability+=probabilities_category_c_service_time[i];
        }

        if (flag_3&&total_probability!=1)
        {
            cerr<<"\nError: Probabilities must sum to 1. Please try again."<<endl;
            flag_3=false;
        }

    } while (!flag_3);
    cout<<endl;


    cout << "===============================" << endl;
    cout << "     Car Simulation Program    " << endl;
    cout << "===============================" << endl;


    //Input the number of cars to simulate
    int num_cars_to_simulate;
    cout<<"Enter the number of cars to simulate: ";
    cin>>num_cars_to_simulate;

    while (num_cars_to_simulate<=0)
    {
        cout<<"Please enter a positive number for cars to simulate: ";
        cin>>num_cars_to_simulate;
    }

    //Dynamically create an array of car objects
    car* cars[num_cars_to_simulate];
    for (int i =0;i<num_cars_to_simulate;i++)
    {
        cars[i]=new car();  //allocate memory for each car object.
    }

    // Input the number of simulation runs
    int num_of_runs;
    cout<<"Enter the number of simulation runs: ";
    cin>>num_of_runs;

    while (num_of_runs<=0)
    {
        cout<<"Please enter a positive number for simulation runs: ";
        cin>>num_of_runs;
    }


    //allocate 2D arrays for storing random values for each run and car.
    char** random_list_generate_car_category=new char*[num_of_runs];
    int** random_list_generate_time_between_arrivals=new int*[num_of_runs];
    int** random_list_generate_service_time_for_category_a_b=new int*[num_of_runs];
    int** random_list_generate_service_time_for_category_c=new int*[num_of_runs];
    float** random_list_generate_going_to_95_pump_or_not=new float*[num_of_runs];
    float** random_list_generate_going_to_90_pump_or_not=new float*[num_of_runs];

    //allocate memory for each run.
    for (int i=0;i<num_of_runs;i++)
    {
        random_list_generate_car_category[i]=new char[num_cars_to_simulate];
        random_list_generate_time_between_arrivals[i]=new int[num_cars_to_simulate];
        random_list_generate_service_time_for_category_a_b[i]=new int[num_cars_to_simulate];
        random_list_generate_service_time_for_category_c[i]=new int[num_cars_to_simulate];
        random_list_generate_going_to_95_pump_or_not[i]=new float[num_cars_to_simulate];
        random_list_generate_going_to_90_pump_or_not[i]=new float[num_cars_to_simulate];
    }

    //Generate random values for each car in each run.
    for(int i=0;i<num_of_runs;i++)
    {
        for (int k=0;k<num_cars_to_simulate;k++)
        {
             random_list_generate_car_category[i][k]=generate_car_category(prob_a,prob_b,prob_c);
             random_list_generate_time_between_arrivals[i][k]=generate_time_between_arrivals(values_time_between_arrivals,probabilities_time_between_arrivals,num_ranges_time_between_arrivals);
             random_list_generate_service_time_for_category_a_b[i][k]=generate_service_time_for_category_a_b(values_category_a_b_service_time,probabilities_category_a_b_service_time,num_ranges_category_a_b_service_time);
             random_list_generate_service_time_for_category_c[i][k]=generate_service_time_for_category_c(values_category_c_service_time,probabilities_category_c_service_time,num_ranges_category_c_service_time);
             random_list_generate_going_to_95_pump_or_not[i][k]=(float)(rand()%10)/10+0.1;
             random_list_generate_going_to_90_pump_or_not[i][k]=(float)(rand()%10)/10+0.1;
        }
    }



    //Variables to track the last busy time of each pump.
    int last_95_octane_busy_time=0;
    int last_90_octane_busy_time=0;
    int last_gas_busy_time=0;

    //Queues to store numbers of cars waiting in each pump.
    queue<int> num_waiting_95_octane;
    queue<int> num_waiting_90_octane;
    queue<int> num_waiting_gas;

    //Variable to store total time between arrivals.
    int total_time_between_arrivals;

    //Variables to store total service times for each pump.
    int total_service_time_95=0;
    int total_service_time_90=0;
    int total_service_time_gas=0;

    //Variables to store total service times for each car category.
    int total_service_time_category_a=0;
    int total_service_time_category_b=0;
    int total_service_time_category_c=0;

    //Variables to store total waiting times for each pump
    int total_waiting_time_95=0;
    int total_waiting_time_90=0;
    int total_waiting_time_gas=0;

    //Counters for the number of cars served by each pump.
    int num_cars_served_by_95=0;
    int num_cars_served_by_90=0;
    int num_cars_served_by_gas=0;

    //Total waiting time for all cars.
    int total_waiting_time_all_cars=0;

    //Queues to store maximum number of cars waiting in each pump.
    int max_queue_length_95=0;
    int max_queue_length_90=0;
    int max_queue_length_gas=0;

    //Counters to count the number of cars that waited for each pump.
    int num_cars_that_waited_95=0;
    int num_cars_that_waited_90=0;
    int num_cars_that_waited_gas=0;

    //Counters to count the number of cars fpr each category.
    int num_category_a=0;
    int num_category_b=0;
    int num_category_c=0;

    //Arrays to store statistics across multiple simulation runs.
    int* list_total_simulation_run_time=new int[num_of_runs];  //Total simulation run times for all runs.

    //Average service time for each pump.
    float* average_service_time_95=new float[num_of_runs];
    float* average_service_time_90=new float[num_of_runs];
    float* average_service_time_gas=new float[num_of_runs];

    //Average time between arrivals
    float* average_time_between_arrivals=new float[num_of_runs];

    //Average service time for each car category.
    float* average_service_time_category_a=new float[num_of_runs];
    float* average_service_time_category_b=new float[num_of_runs];
    float* average_service_time_category_c=new float[num_of_runs];

    //Average waiting time for each pump.
    float* average_waiting_time_95=new float[num_of_runs];
    float* average_waiting_time_90=new float[num_of_runs];
    float* average_waiting_time_gas=new float[num_of_runs];

    float* average_waiting_time_all_cars=new float[num_of_runs];  //Average waiting time for all cars.

    //lists for Maximum queue length for each pump.
    int* list_max_queue_length_95=new int[num_of_runs];
    int* list_max_queue_length_90=new int[num_of_runs];
    int* list_max_queue_length_gas=new int[num_of_runs];

    //Probability of a car waits for each pump.
    float* probability_car_waits_95=new float[num_of_runs];
    float* probability_car_waits_90=new float[num_of_runs];
    float* probability_car_waits_gas=new float[num_of_runs];

    //Probability of idle time for each pump.
    float* probability_idle_time_95=new float[num_of_runs];
    float* probability_idle_time_90=new float[num_of_runs];
    float* probability_idle_time_gas=new float[num_of_runs];

    //Variables and queues for extra pumps.
    queue<int> num_waiting_gas_2;    //Number of cars waiting for the second Gas pump.
    int last_gas_busy_time_2=0;      //Last busy time for the second Gas pump.
    int total_waiting_time_gas_2=0;  //Total waiting time for the second Gas pump.
    float* average_waiting_time_all_cars_after_gas_addition=new float[num_of_runs];   //Average waiting time after adding second Gas pump.

    queue<int>num_waiting_90_octane_2;  //Number of cars waiting for the second 90 Octane pump.
    int last_90_octane_busy_time_2=0;   //Last busy time for the second 90 Octane pump.
    int total_waiting_time_90_2=0;      //Total waiting time for the 90 Octane pump.
    float *average_waiting_time_all_cars_after_90_addition=new float[num_of_runs];   //Average waiting time after adding second 90 Octane pump.

    queue<int>num_waiting_95_octane_2;  //Number of cars waiting for the second 95 Octane pump.
    int last_95_octane_busy_time_2=0;   //Last busy time for the second 95 Octane pump.
    int total_waiting_time_95_2=0;      //Total waiting time for the 95 Octane pump.
    float *average_waiting_time_all_cars_after_95_addition=new float[num_of_runs];   //Average waiting time after adding second 95 Octane pump.


    //Open an text file for writing the simulation tables
    ofstream output("Petrol Station Simulation Tables (Three Main Pumps).txt");
    output<<"Simulation Summary:"<<endl;
    output<<"-------------------"<<endl;
    output<<"Number of Tables: "<<num_of_runs<<endl;
    output<<"Number of Cars Simulated per Table: "<<num_cars_to_simulate<<endl<<endl;


    //Outer loop to Iterate through each simulation run
    for(int k=0;k<num_of_runs;k++)
{
    //Initialize variables for each run
    last_95_octane_busy_time=0;
    last_90_octane_busy_time=0;
    last_gas_busy_time=0;
    total_service_time_95=0;
    total_service_time_90=0;
    total_service_time_gas=0;
    total_time_between_arrivals=0;
    total_service_time_category_a=0;
    total_service_time_category_b=0;
    total_service_time_category_c=0;
    total_waiting_time_95=0;
    total_waiting_time_90=0;
    total_waiting_time_gas=0;
    num_cars_served_by_95=0;
    num_cars_served_by_90=0;
    num_cars_served_by_gas=0;
    total_waiting_time_all_cars=0;
    max_queue_length_95=0;
    max_queue_length_90=0;
    max_queue_length_gas=0;
    num_cars_that_waited_95=0;
    num_cars_that_waited_90=0;
    num_cars_that_waited_gas=0;
    num_category_a=0;
    num_category_b=0;
    num_category_c=0;

    //Inner loop to Simulate each car
        for (int i=0;i<num_cars_to_simulate;i++)
     {
          //Set car number
          cars[i]->set_car_number(i+1);

        //Set time between arrivals
        if (i==0)
        {
           cars[i]->set_time_between_arrivals(-1);
        }
        else
        {
            cars[i]->set_time_between_arrivals(random_list_generate_time_between_arrivals[k][i]);
        }

        //Set arrival time
        if (i==0)
        {
            cars[i]->set_arrival_time(0);
        }
        else
        {
            cars[i]->set_arrival_time(cars[i]->get_time_between_arrivals()+cars[i-1]->get_arrival_time());
        }

        //Set car category
        cars[i]->set_car_category(random_list_generate_car_category[k][i]);

        //Set service time
        if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_a_b[k][i]);
        }
        else
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_c[k][i]);
        }

        //Queues for 95, 90 Octane and Gas pumps to remove completed cars
        while(!num_waiting_95_octane.empty()&&cars[num_waiting_95_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_95_octane.pop();
        }

        while(!num_waiting_90_octane.empty()&&cars[num_waiting_90_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_90_octane.pop();
        }

        while(!num_waiting_gas.empty()&&cars[num_waiting_gas.front()]->get_leave_time()<=cars[i]->get_arrival_time())
        {
            num_waiting_gas.pop();
        }

        //Handle service start times for 95 Octane pump
        if (cars[i]->get_car_category()=='C')
        {
            cars[i]->set_service_start_95_octane(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (num_waiting_90_octane.size()>3&&(random_list_generate_going_to_95_pump_or_not[k][i]>0&&random_list_generate_going_to_95_pump_or_not[k][i]<=0.6))
            {
                num_waiting_95_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                {
                    cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                }
            }
            else
            {
                cars[i]->set_service_start_95_octane(-1);
            }
        }
        else
        {
            num_waiting_95_octane.push(i);
            if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                {
                    cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                }
        }

        //Handle service start times for 90 Octane pump
        if (cars[i]->get_car_category()=='A')
        {
            cars[i]->set_service_start_90_octane(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                cars[i]->set_service_start_90_octane(-1);
            }
            else
            {
                num_waiting_90_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                {
                    cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                }
            }
        }
        else
        {
            if (num_waiting_gas.size()>4&&(random_list_generate_going_to_90_pump_or_not[k][i]>0&&random_list_generate_going_to_90_pump_or_not[k][i]<=0.4))
            {
                num_waiting_90_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                {
                    cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                }
            }
            else
            {
                cars[i]->set_service_start_90_octane(-1);
            }
        }

        //Handle service start times for Gas pump
         if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_start_gas(-1);
        }
        else
        {
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                cars[i]->set_service_start_gas(-1);
            }
            else
            {
                num_waiting_gas.push(i);
                if (cars[i]->get_arrival_time()>=last_gas_busy_time)
                {
                    cars[i]->set_service_start_gas(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_gas(last_gas_busy_time);
                }
            }
        }

        //Set leave time based on the pump used
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_95_octane()+cars[i]->get_service_time());
        }
        else if (cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_90_octane()+cars[i]->get_service_time());
        }
        else
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_gas()+cars[i]->get_service_time());
        }

        //Calculate idle time for each pump
        if (i==0)
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                 cars[i]->set_idle_time_95(0);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                 cars[i]->set_idle_time_90(0);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                 cars[i]->set_idle_time_gas(0);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
        }
        else
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                cars[i]->set_idle_time_95(cars[i]->get_service_start_95_octane()-last_95_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                cars[i]->set_idle_time_90(cars[i]->get_service_start_90_octane()-last_90_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                cars[i]->set_idle_time_gas(cars[i]->get_service_start_gas()-last_gas_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
        }

        /*Determine the Fuel type for each car
          and Calculate number of cars served in each pump*/
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            cars[i]->set_fuel_type("95 Octane");
            num_cars_served_by_95++;
        }
        else if (cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_fuel_type("90 Octane");
            num_cars_served_by_90++;
        }
        else
        {
            cars[i]->set_fuel_type("Gas");
            num_cars_served_by_gas++;
        }

        //Updating last time busy for each pump
        if (cars[i]->get_service_start_95_octane()!=-1)
        {
            last_95_octane_busy_time=cars[i]->get_leave_time();
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            last_90_octane_busy_time=cars[i]->get_leave_time();
        }
        else
        {
            last_gas_busy_time=cars[i]->get_leave_time();
        }

        //Calculate total service time for each pump
        if (cars[i]->get_service_start_95_octane()!=-1)
        {
            total_service_time_95+=cars[i]->get_service_time();
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            total_service_time_90+=cars[i]->get_service_time();
        }
        else
        {
            total_service_time_gas+=cars[i]->get_service_time();
        }

        //Calculate total service time for each pump
        if (cars[i]->get_car_category()=='A')
        {
            total_service_time_category_a+=cars[i]->get_service_time();
        }
        else if (cars[i]->get_car_category()=='B')
        {
            total_service_time_category_b+=cars[i]->get_service_time();
        }
        else
        {
            total_service_time_category_c+=cars[i]->get_service_time();
        }

        //Calculate waiting time for each pump
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            total_waiting_time_95+=(cars[i]->get_service_start_95_octane()-cars[i]->get_arrival_time());
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            total_waiting_time_90+=(cars[i]->get_service_start_90_octane()-cars[i]->get_arrival_time());
        }
        else
        {
            total_waiting_time_gas+=(cars[i]->get_service_start_gas()-cars[i]->get_arrival_time());
        }

        //Track the maximum queue lengths for each pump
        max_queue_length_95=max(max_queue_length_95,(int)num_waiting_95_octane.size());
        max_queue_length_90=max(max_queue_length_90,(int)num_waiting_90_octane.size());
        max_queue_length_gas=max(max_queue_length_gas,(int)num_waiting_gas.size());

        //Count the number of cars that waited for service for each pump
        if(cars[i]->get_fuel_type()=="95 Octane")
        {
            if (cars[i]->get_arrival_time()!=cars[i]->get_service_start_95_octane())
            {
                num_cars_that_waited_95++;
            }
        }
        else if(cars[i]->get_fuel_type()=="90 Octane")
        {
            if (cars[i]->get_arrival_time()!=cars[i]->get_service_start_90_octane())
            {
                num_cars_that_waited_90++;
            }
        }
        else
        {
            if (cars[i]->get_arrival_time()!=cars[i]->get_service_start_gas())
            {
                num_cars_that_waited_gas++;
            }
        }

        //Count the number of cars for each category.
        if (cars[i]->get_car_category()=='A')
        {
            num_category_a++;
        }
        else if (cars[i]->get_car_category()=='B')
        {
            num_category_b++;
        }
        else
        {
            num_category_c++;
        }

        //Calculate the total time between arrivals
        if (i!=0)
        {
            total_time_between_arrivals+=random_list_generate_time_between_arrivals[k][i];
        }

        //Clear the queues for each pump after the last car done
        if (i==num_cars_to_simulate-1)
        {
            while(!num_waiting_95_octane.empty())
            {
                num_waiting_95_octane.pop();
            }
            while(!num_waiting_90_octane.empty())
            {
                num_waiting_90_octane.pop();
            }
            while(!num_waiting_gas.empty())
            {
                num_waiting_gas.pop();
            }
        }
     }


     //Update statistics for the simulation run
     list_total_simulation_run_time[k]=std::max({last_95_octane_busy_time,last_90_octane_busy_time,last_gas_busy_time});
     total_waiting_time_all_cars=total_waiting_time_95+total_waiting_time_90+total_waiting_time_gas;
     average_service_time_95[k]=total_service_time_95/(float)num_cars_served_by_95;
     average_service_time_90[k]=total_service_time_90/(float)num_cars_served_by_90;
     average_service_time_gas[k]=total_service_time_gas/(float)num_cars_served_by_gas;
     average_time_between_arrivals[k]=total_time_between_arrivals/(float)num_cars_to_simulate;
     average_service_time_category_a[k]=total_service_time_category_a/(float)num_category_a;
     average_service_time_category_b[k]=total_service_time_category_b/(float)num_category_b;
     average_service_time_category_c[k]=total_service_time_category_c/(float)num_category_c;
     average_waiting_time_95[k]=total_waiting_time_95/(float)num_cars_served_by_95;
     average_waiting_time_90[k]=total_waiting_time_90/(float)num_cars_served_by_90;
     average_waiting_time_gas[k]=total_waiting_time_gas/(float)num_cars_served_by_gas;
     average_waiting_time_all_cars[k]=total_waiting_time_all_cars/(float)num_cars_to_simulate;
     list_max_queue_length_95[k]=max_queue_length_95;
     list_max_queue_length_90[k]=max_queue_length_90;
     list_max_queue_length_gas[k]=max_queue_length_gas;
     probability_car_waits_95[k]=num_cars_that_waited_95/(float)num_cars_served_by_95;
     probability_car_waits_90[k]=num_cars_that_waited_90/(float)num_cars_served_by_90;
     probability_car_waits_gas[k]=num_cars_that_waited_gas/(float)num_cars_served_by_gas;
     probability_idle_time_95[k]=(list_total_simulation_run_time[k]-total_service_time_95)/(float)list_total_simulation_run_time[k];
     probability_idle_time_90[k]=(list_total_simulation_run_time[k]-total_service_time_90)/(float)list_total_simulation_run_time[k];
     probability_idle_time_gas[k]=(list_total_simulation_run_time[k]-total_service_time_gas)/(float)list_total_simulation_run_time[k];


     //Write table header to the output file
output<<endl<<"========================================================================= Table Number: "<<k+1<<" ========================================================================="<<endl;
output<<endl;

output<<setw(10)<<"Car No"<<setw(12)<<"Category"<<setw(20)<<"Time Between"<<setw(12)<<"Arrival"
       <<setw(12)<<"Start 95"<<setw(12)<<"Start 90"<<setw(12)<<"Start Gas"
       << setw(12)<<"Service"<<setw(12)<<"Leave"<<setw(12)<<"Idle 95"
       << setw(12)<<"Idle 90"<<setw(12)<<"Idle Gas"<<setw(15)<<"Fuel Type"<<endl;

output<<setw(10)<<""<<setw(12)<<""<< setw(20)<<"Arrivals"<<setw(12)<<"Time"
       <<setw(12)<<"Time"<<setw(12)<<"Time"<<setw(12)<<"Time"
       <<setw(12)<<"Time"<<setw(12)<<"Time"<< setw(12)<<"Time"
       <<setw(12)<<"Time"<<setw(12)<<"Time"<< endl;

output<<string(165,'=')<<endl;


//Write car data to the table
for (int i=0;i< num_cars_to_simulate;i++)
    {
        output<<setw(10)<<cars[i]->get_car_number()
           <<setw(12)<<cars[i]->get_car_category()
           <<setw(20)<<(cars[i]->get_time_between_arrivals()==-1?"-":to_string(cars[i]->get_time_between_arrivals()))
           <<setw(12)<<cars[i]->get_arrival_time()
           <<setw(12)<<(cars[i]->get_service_start_95_octane()==-1?"-":to_string(cars[i]->get_service_start_95_octane()))
           <<setw(12)<<(cars[i]->get_service_start_90_octane()==-1?"-":to_string(cars[i]->get_service_start_90_octane()))
           <<setw(12)<<(cars[i]->get_service_start_gas()==-1? "-":to_string(cars[i]->get_service_start_gas()))
           <<setw(12)<<cars[i]->get_service_time()
           <<setw(12)<<cars[i]->get_leave_time()
           <<setw(12)<<(cars[i]->get_idle_time_95()==-1?"-":to_string(cars[i]->get_idle_time_95()))
           <<setw(12)<<(cars[i]->get_idle_time_90()==-1?"-":to_string(cars[i]->get_idle_time_90()))
           <<setw(12)<<(cars[i]->get_idle_time_gas()==-1?"-":to_string(cars[i]->get_idle_time_gas()))
           <<setw(15)<<cars[i]->get_fuel_type()<<endl;

    output<<string(165,'-')<<endl;
}

output<<endl<<endl;


}
output.close();

/*This function call is used to save the simulation results for 3 main pumps
  The data will be saved in a CSV file called "Smulation_Results (Three Main Pumps)" */
write_to_csv("Simulation_Results (Three Main Pumps).csv",num_of_runs,average_service_time_category_a,average_service_time_category_b,average_service_time_category_c,average_service_time_95,average_service_time_90,average_service_time_gas,
                 average_waiting_time_95,average_waiting_time_90,average_waiting_time_gas,average_waiting_time_all_cars,list_max_queue_length_95,list_max_queue_length_90,list_max_queue_length_gas,probability_car_waits_95,probability_car_waits_90,probability_car_waits_gas,
                 probability_idle_time_95,probability_idle_time_90,probability_idle_time_gas);


//Initialize variables to store sums for each variable in all simulation runs
float sum_average_service_time_95=0;
float sum_average_service_time_90=0;
float sum_average_service_time_gas=0;
float sum_average_time_between_arrivals=0;
float sum_average_service_time_category_a=0;
float sum_average_service_time_category_b=0;
float sum_average_service_time_category_c=0;
float sum_average_waiting_time_95=0;
float sum_average_waiting_time_90=0;
float sum_average_waiting_time_gas=0;
float sum_average_waiting_time_all_cars=0;
float sum_list_max_queue_length_95=0;
float sum_list_max_queue_length_90=0;
float sum_list_max_queue_length_gas=0;
float sum_probability_car_waits_95=0;
float sum_probability_car_waits_90=0;
float sum_probability_car_waits_gas=0;
float sum_probability_idle_time_95=0;
float sum_probability_idle_time_90=0;
float sum_probability_idle_time_gas=0;

//Iterate through each simulation run to calculate sums for variable
for (int i=0;i<num_of_runs;i++)
{
    sum_average_service_time_95+=average_service_time_95[i];
    sum_average_service_time_90+=average_service_time_90[i];
    sum_average_service_time_gas+=average_service_time_gas[i];
    sum_average_time_between_arrivals+=average_time_between_arrivals[i];
    sum_average_service_time_category_a+=average_service_time_category_a[i];
    sum_average_service_time_category_b+=average_service_time_category_b[i];
    sum_average_service_time_category_c+=average_service_time_category_c[i];
    sum_average_waiting_time_95+=average_waiting_time_95[i];
    sum_average_waiting_time_90+=average_waiting_time_90[i];
    sum_average_waiting_time_gas+=average_waiting_time_gas[i];
    sum_average_waiting_time_all_cars+=average_waiting_time_all_cars[i];
    sum_list_max_queue_length_95+=list_max_queue_length_95[i];
    sum_list_max_queue_length_90+=list_max_queue_length_90[i];
    sum_list_max_queue_length_gas+=list_max_queue_length_gas[i];
    sum_probability_car_waits_95+=probability_car_waits_95[i];
    sum_probability_car_waits_90+=probability_car_waits_90[i];
    sum_probability_car_waits_gas+=probability_car_waits_gas[i];
    sum_probability_idle_time_95+=probability_idle_time_95[i];
    sum_probability_idle_time_90+=probability_idle_time_90[i];
    sum_probability_idle_time_gas+=probability_idle_time_gas[i];
}

// Display the summary of simulation results
cout << "\n=========== Simulation Results ===========\n";

cout << "\n--- Average Time between arrivals (mins/car) ---\n";
cout << "Average Time: " << sum_average_time_between_arrivals / num_of_runs << "\n";

cout << "\n--- Average Service Time (mins/car) ---\n";
cout << "Category A: " << sum_average_service_time_category_a / num_of_runs << "\n";
cout << "Category B: " << sum_average_service_time_category_b / num_of_runs << "\n";
cout << "Category C: " << sum_average_service_time_category_c / num_of_runs << "\n";

cout << "\n--- Average Service Time (mins/car) ---\n";
cout << "95 Octane: " << sum_average_service_time_95 / num_of_runs << "\n";
cout << "90 Octane: " << sum_average_service_time_90 / num_of_runs << "\n";
cout << "Gas:       " << sum_average_service_time_gas / num_of_runs << "\n";

cout << "\n--- Average Waiting Time (mins/car) ---\n";
cout << "95 Octane: " << sum_average_waiting_time_95 / num_of_runs << "\n";
cout << "90 Octane: " << sum_average_waiting_time_90 / num_of_runs << "\n";
cout << "Gas:       " << sum_average_waiting_time_gas / num_of_runs << "\n";
cout << "All Cars:  " << sum_average_waiting_time_all_cars / num_of_runs << "\n";

cout << "\n--- Average Maximum Queue Length ---\n";
cout << "95 Octane: " << sum_list_max_queue_length_95 / (float)num_of_runs << "\n";
cout << "90 Octane: " << sum_list_max_queue_length_90 / (float)num_of_runs << "\n";
cout << "Gas:       " << sum_list_max_queue_length_gas / (float)num_of_runs << "\n";

cout << "\n--- Probability That a Car Waits ---\n";
cout << "95 Octane: " << sum_probability_car_waits_95 / num_of_runs << "\n";
cout << "90 Octane: " << sum_probability_car_waits_90 / num_of_runs << "\n";
cout << "Gas:       " << sum_probability_car_waits_gas / num_of_runs << "\n";

cout << "\n--- Probability of Idle Time ---\n";
cout << "95 Octane: " << sum_probability_idle_time_95 / num_of_runs << "\n";
cout << "90 Octane: " << sum_probability_idle_time_90 / num_of_runs << "\n";
cout << "Gas:       " << sum_probability_idle_time_gas / num_of_runs << "\n";

cout << "\n===========================================\n\n";



//Open an text file for writing the simulation tables
ofstream output_2("Petrol Station Simulation Tables (Extra Gas Pump).txt");
    output_2<<"Simulation Summary:"<<endl;
    output_2<<"-------------------"<<endl;
    output_2<<"Number of Tables: "<<num_of_runs<<endl;
    output_2<<"Number of Cars Simulated per Table: "<<num_cars_to_simulate<<endl<<endl;


//Addition of an Extra Gas Pump

//Outer loop to Iterate through each simulation run
    for(int k=0;k<num_of_runs;k++)
{
    //Initialize variables for each run
    last_95_octane_busy_time=0;
    last_90_octane_busy_time=0;
    last_gas_busy_time=0;
    last_gas_busy_time_2=0;
    total_waiting_time_95=0;
    total_waiting_time_90=0;
    total_waiting_time_gas=0;
    total_waiting_time_gas_2=0;
    total_waiting_time_all_cars=0;


    //Inner loop to Simulate each car
        for (int i=0;i<num_cars_to_simulate;i++)
     {
        //Set car number
        cars[i]->set_car_number(i+1);

        //Set time between arrivals
        if (i==0)
        {
           cars[i]->set_time_between_arrivals(-1);
        }
        else
        {
            cars[i]->set_time_between_arrivals(random_list_generate_time_between_arrivals[k][i]);
        }

        //Set arrival time
        if (i==0)
        {
            cars[i]->set_arrival_time(0);
        }
        else
        {
            cars[i]->set_arrival_time(cars[i]->get_time_between_arrivals()+cars[i-1]->get_arrival_time());
        }

        //Set car category
        cars[i]->set_car_category(random_list_generate_car_category[k][i]);

        //Set service time
        if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_a_b[k][i]);
        }
        else
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_c[k][i]);
        }

        //Queues for 95, 90 Octane ,Gas and extra Gas pumps to remove completed cars
        while(!num_waiting_95_octane.empty()&&cars[num_waiting_95_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_95_octane.pop();
        }

        while(!num_waiting_90_octane.empty()&&cars[num_waiting_90_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_90_octane.pop();
        }

        while(!num_waiting_gas.empty()&&cars[num_waiting_gas.front()]->get_leave_time()<=cars[i]->get_arrival_time())
        {
            num_waiting_gas.pop();
        }
        while(!num_waiting_gas_2.empty()&&cars[num_waiting_gas_2.front()]->get_leave_time()<=cars[i]->get_arrival_time())
        {
            num_waiting_gas_2.pop();
        }

        //Handle service start times for 95 Octane pump
        if (cars[i]->get_car_category()=='C')
        {
            cars[i]->set_service_start_95_octane(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (num_waiting_90_octane.size()>3&&(random_list_generate_going_to_95_pump_or_not[k][i]>0&&random_list_generate_going_to_95_pump_or_not[k][i]<=0.6))
            {
                num_waiting_95_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                {
                    cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                }
            }
            else
            {
                cars[i]->set_service_start_95_octane(-1);
            }
        }
        else
        {
            num_waiting_95_octane.push(i);
            if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                {
                    cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                }
        }

        //Handle service start times for 90 Octane pump
        if (cars[i]->get_car_category()=='A')
        {
            cars[i]->set_service_start_90_octane(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                cars[i]->set_service_start_90_octane(-1);
            }
            else
            {
                num_waiting_90_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                {
                    cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                }
            }
        }
        else
        {
            if (num_waiting_gas.size()>4&&num_waiting_gas_2.size()>4&&(random_list_generate_going_to_90_pump_or_not[k][i]>0&&random_list_generate_going_to_90_pump_or_not[k][i]<=0.4))
            {
                num_waiting_90_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                {
                    cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                }
            }
            else
            {
                cars[i]->set_service_start_90_octane(-1);
            }
        }

        //Handle service start times for the Gas pump and the extra Gas pump.
         if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_start_gas(-1);
            cars[i]->set_service_start_gas_2(-1);
        }
        else
        {
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                cars[i]->set_service_start_gas(-1);
                cars[i]->set_service_start_gas_2(-1);
            }
            else
            {
                if (num_waiting_gas.size()<=num_waiting_gas_2.size())
                    {
                    num_waiting_gas.push(i);
                    cars[i]->set_service_start_gas_2(-1);
                    if (cars[i]->get_arrival_time()>=last_gas_busy_time)
                        {
                        cars[i]->set_service_start_gas(cars[i]->get_arrival_time());
                        }
                    else
                        {
                            cars[i]->set_service_start_gas(last_gas_busy_time);
                        }
                    }
                else
                    {
                        num_waiting_gas_2.push(i);
                        cars[i]->set_service_start_gas(-1);
                        if (cars[i]->get_arrival_time()>=last_gas_busy_time_2)
                        {
                        cars[i]->set_service_start_gas_2(cars[i]->get_arrival_time());
                        }
                    else
                        {
                            cars[i]->set_service_start_gas_2(last_gas_busy_time_2);
                        }
                    }
            }
        }

        //Set leave time based on the pump used
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_95_octane()+cars[i]->get_service_time());
        }
        else if (cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_90_octane()+cars[i]->get_service_time());
        }
        else if(cars[i]->get_service_start_gas()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_gas()+cars[i]->get_service_time());
        }
        else
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_gas_2()+cars[i]->get_service_time());
        }

        //Calculate idle time for each pump
          if (i==0)
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                 cars[i]->set_idle_time_95(0);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                 cars[i]->set_idle_time_90(0);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                 cars[i]->set_idle_time_gas(0);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
            if (cars[i]->get_service_start_gas_2()!=-1)
            {
                cars[i]->set_idle_time_gas_2(0);
            }
            else
            {
                cars[i]->set_idle_time_gas_2(-1);
            }
        }
        else
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                cars[i]->set_idle_time_95(cars[i]->get_service_start_95_octane()-last_95_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                cars[i]->set_idle_time_90(cars[i]->get_service_start_90_octane()-last_90_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                cars[i]->set_idle_time_gas(cars[i]->get_service_start_gas()-last_gas_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
            if(cars[i]->get_service_start_gas_2()!=-1)
            {
                cars[i]->set_idle_time_gas_2(cars[i]->get_service_start_gas_2()-last_gas_busy_time_2);
            }
            else
            {
                cars[i]->set_idle_time_gas_2(-1);
            }
        }

         //Determine the Fuel type for each car
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            cars[i]->set_fuel_type("95 Octane");
        }
        else if (cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_fuel_type("90 Octane");
        }
        else
        {
            cars[i]->set_fuel_type("Gas");
        }

        //Updating last time busy for each pump
        if (cars[i]->get_service_start_95_octane()!=-1)
        {
            last_95_octane_busy_time=cars[i]->get_leave_time();
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            last_90_octane_busy_time=cars[i]->get_leave_time();
        }
        else if(cars[i]->get_service_start_gas()!=-1)
        {
            last_gas_busy_time=cars[i]->get_leave_time();
        }
        else
        {
            last_gas_busy_time_2=cars[i]->get_leave_time();
        }

        //Calculate waiting time for each pump
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            total_waiting_time_95+=(cars[i]->get_service_start_95_octane()-cars[i]->get_arrival_time());
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            total_waiting_time_90+=(cars[i]->get_service_start_90_octane()-cars[i]->get_arrival_time());
        }
        else if(cars[i]->get_service_start_gas()!=-1)
        {
            total_waiting_time_gas+=(cars[i]->get_service_start_gas()-cars[i]->get_arrival_time());
        }
        else
        {
            total_waiting_time_gas_2+=(cars[i]->get_service_start_gas_2()-cars[i]->get_arrival_time());
        }

        //Clear the queues for each pump after the last car done
        if (i==num_cars_to_simulate-1)
        {
            while(!num_waiting_95_octane.empty())
            {
                num_waiting_95_octane.pop();
            }
            while(!num_waiting_90_octane.empty())
            {
                num_waiting_90_octane.pop();
            }
            while(!num_waiting_gas.empty())
            {
                num_waiting_gas.pop();
            }
            while(!num_waiting_gas_2.empty())
            {
                num_waiting_gas_2.pop();
            }
        }
     }

     //Update total and average waiting time for the simulation run
     total_waiting_time_all_cars=total_waiting_time_95+total_waiting_time_90+total_waiting_time_gas+total_waiting_time_gas_2;
     average_waiting_time_all_cars_after_gas_addition[k]=total_waiting_time_all_cars/(float)num_cars_to_simulate;


//Write table header to the output file
output_2<<endl<<"========================================================================= Table Number: "<<k+1<<" ========================================================================="<<endl;
output_2<<endl;

output_2<< setw(10) << "Car No" << setw(12) << "Category" << setw(12) << "Arrival" << setw(12) << "Start 95"
       << setw(12) << "Start 90" << setw(12) << "Start Gas" << setw(15) << "Start Gas_2"
       << setw(12) << "Service" << setw(12) << "Leave" << setw(12) << "Idle 95"
       << setw(12) << "Idle 90" << setw(12) << "Idle Gas" << setw(15) << "Idle Gas_2" << endl;

output_2 << setw(10) << "" << setw(12) << "" << setw(12) << "Time" << setw(12) << "Time"
       << setw(12) << "Time" << setw(12) << "Time" << setw(15) << "Time"
       << setw(12) << "Time" << setw(12) << "Time" << setw(12) << "Time"
       << setw(12) << "Time" << setw(12) << "Time" <<setw(12)<<"Time"<< endl;

output_2 << string(165, '=') << endl;

//Write car data to the table
for (int i=0;i<num_cars_to_simulate; i++)
    {
    output_2 << setw(10) << cars[i]->get_car_number()
           << setw(12) << cars[i]->get_car_category()
           << setw(12) << cars[i]->get_arrival_time()
           << setw(12) << (cars[i]->get_service_start_95_octane() == -1 ? "-" : to_string(cars[i]->get_service_start_95_octane()))
           << setw(12) << (cars[i]->get_service_start_90_octane() == -1 ? "-" : to_string(cars[i]->get_service_start_90_octane()))
           << setw(12) << (cars[i]->get_service_start_gas() == -1 ? "-" : to_string(cars[i]->get_service_start_gas()))
           <<setw(15)<<(cars[i]->get_service_start_gas_2() == -1 ? "-" : to_string(cars[i]->get_service_start_gas_2()))
           << setw(12) << cars[i]->get_service_time()
           << setw(12) << cars[i]->get_leave_time()
           << setw(12) << (cars[i]->get_idle_time_95() == -1 ? "-" : to_string(cars[i]->get_idle_time_95()))
           << setw(12) << (cars[i]->get_idle_time_90() == -1 ? "-" : to_string(cars[i]->get_idle_time_90()))
           << setw(12) << (cars[i]->get_idle_time_gas() == -1 ? "-" : to_string(cars[i]->get_idle_time_gas()))
           << setw(15) <<(cars[i]->get_idle_time_gas_2() == -1 ? "-" : to_string(cars[i]->get_idle_time_gas_2()))<<endl;

    output_2 << string(165, '-') << endl;
}

output_2<<endl<<endl;

}

output_2.close();

//Calculate the average waiting time for all cars from the extra Gas pump simulation run.
float sum_average_waiting_time_all_cars_after_gas_addition=0;
for (int i=0;i<num_of_runs;i++)
{
    sum_average_waiting_time_all_cars_after_gas_addition+=average_waiting_time_all_cars_after_gas_addition[i];
}


//Open an text file for writing the simulation tables
ofstream output_3("Petrol Station Simulation Tables (Extra 90 Pump).txt");
    output_3<<"Simulation Summary:"<<endl;
    output_3<<"-------------------"<<endl;
    output_3<<"Number of Tables: "<<num_of_runs<<endl;
    output_3<<"Number of Cars Simulated per Table: "<<num_cars_to_simulate<<endl<<endl;


//Addition of an Extra 90 octane Pump

//Outer loop to Iterate through each simulation run
for(int k=0;k<num_of_runs;k++)
{
    //Initialize variables for each run
    last_95_octane_busy_time=0;
    last_90_octane_busy_time=0;
    last_gas_busy_time=0;
    last_90_octane_busy_time_2=0;
    total_waiting_time_95=0;
    total_waiting_time_90=0;
    total_waiting_time_gas=0;
    total_waiting_time_90_2=0;
    total_waiting_time_all_cars=0;


    //Inner loop to Simulate each car
        for (int i=0;i<num_cars_to_simulate;i++)
     {
         //Set car number
        cars[i]->set_car_number(i+1);

        //Set time between arrivals
        if (i==0)
        {
           cars[i]->set_time_between_arrivals(-1);
        }
        else
        {
            cars[i]->set_time_between_arrivals(random_list_generate_time_between_arrivals[k][i]);
        }

        //Set arrival time
        if (i==0)
        {
            cars[i]->set_arrival_time(0);
        }
        else
        {
            cars[i]->set_arrival_time(cars[i]->get_time_between_arrivals()+cars[i-1]->get_arrival_time());
        }

        //Set car category
        cars[i]->set_car_category(random_list_generate_car_category[k][i]);

        //Set service time
        if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_a_b[k][i]);
        }
        else
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_c[k][i]);
        }

        //Queues for 95, 90 Octane ,Gas and extra 90 octane pumps to remove completed cars
        while(!num_waiting_95_octane.empty()&&cars[num_waiting_95_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_95_octane.pop();
        }

        while(!num_waiting_90_octane.empty()&&cars[num_waiting_90_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_90_octane.pop();
        }

        while(!num_waiting_gas.empty()&&cars[num_waiting_gas.front()]->get_leave_time()<=cars[i]->get_arrival_time())
        {
            num_waiting_gas.pop();
        }
        while(!num_waiting_90_octane_2.empty()&&cars[num_waiting_90_octane_2.front()]->get_leave_time()<=cars[i]->get_arrival_time())
        {
            num_waiting_90_octane_2.pop();
        }

        //Handle service start times for 95 Octane pump
        if (cars[i]->get_car_category()=='C')
        {
            cars[i]->set_service_start_95_octane(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (num_waiting_90_octane.size()>3&&num_waiting_90_octane_2.size()>3&&(random_list_generate_going_to_95_pump_or_not[k][i]>0&&random_list_generate_going_to_95_pump_or_not[k][i]<=0.6))
            {
                num_waiting_95_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                {
                    cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                }
            }
            else
            {
                cars[i]->set_service_start_95_octane(-1);
            }
        }
        else
        {
            num_waiting_95_octane.push(i);
            if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                {
                    cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                }
        }


        //Handle service start times for the 90 octane pump and the extra 90 octane pump.
        if (cars[i]->get_car_category()=='A')
        {
            cars[i]->set_service_start_90_octane(-1);
            cars[i]->set_service_start_90_octane_2(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                cars[i]->set_service_start_90_octane(-1);
                cars[i]->set_service_start_90_octane_2(-1);
            }
            else
            {
                if(num_waiting_90_octane.size()<=num_waiting_90_octane_2.size())
                {
                    num_waiting_90_octane.push(i);
                    cars[i]->set_service_start_90_octane_2(-1);
                    if(cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                    {
                        cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                    }
                }
                else
                {
                    num_waiting_90_octane_2.push(i);
                    cars[i]->set_service_start_90_octane(-1);
                    if(cars[i]->get_arrival_time()>=last_90_octane_busy_time_2)
                    {
                        cars[i]->set_service_start_90_octane_2(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_90_octane_2(last_90_octane_busy_time_2);
                    }
                }
            }
        }
        else
        {
            if (num_waiting_gas.size()>4&&(random_list_generate_going_to_90_pump_or_not[k][i]>0&&random_list_generate_going_to_90_pump_or_not[k][i]<=0.4))
            {
                if(num_waiting_90_octane.size()<=num_waiting_90_octane_2.size())
                {
                    num_waiting_90_octane.push(i);
                    cars[i]->set_service_start_90_octane_2(-1);
                    if(cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                    {
                        cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                    }
                }
                else
                {
                    num_waiting_90_octane_2.push(i);
                    cars[i]->set_service_start_90_octane(-1);
                    if(cars[i]->get_arrival_time()>=last_90_octane_busy_time_2)
                    {
                        cars[i]->set_service_start_90_octane_2(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_90_octane_2(last_90_octane_busy_time_2);
                    }
                }

            }
            else
            {
                cars[i]->set_service_start_90_octane(-1);
                cars[i]->set_service_start_90_octane_2(-1);
            }
        }


        //Handle service start times for Gas pump
         if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_start_gas(-1);
        }
        else
        {
            if (cars[i]->get_service_start_90_octane()!=-1||cars[i]->get_service_start_90_octane_2()!=-1)
            {
                cars[i]->set_service_start_gas(-1);
            }
            else
            {
                num_waiting_gas.push(i);
                if (cars[i]->get_arrival_time()>=last_gas_busy_time)
                {
                    cars[i]->set_service_start_gas(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_gas(last_gas_busy_time);
                }
            }
        }

        //Set leave time based on the pump used
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_95_octane()+cars[i]->get_service_time());
        }
        else if (cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_90_octane()+cars[i]->get_service_time());
        }
        else if (cars[i]->get_service_start_90_octane_2()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_90_octane_2()+cars[i]->get_service_time());
        }
        else if (cars[i]->get_service_start_gas()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_gas()+cars[i]->get_service_time());
        }

        //Calculate idle time for each pump
        if (i==0)
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                 cars[i]->set_idle_time_95(0);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                 cars[i]->set_idle_time_90(0);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                 cars[i]->set_idle_time_gas(0);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
            if (cars[i]->get_service_start_90_octane_2()!=-1)
            {
                cars[i]->set_idle_time_90_octane_2(0);
            }
            else
            {
                cars[i]->set_idle_time_90_octane_2(-1);
            }
        }
        else
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                cars[i]->set_idle_time_95(cars[i]->get_service_start_95_octane()-last_95_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                cars[i]->set_idle_time_90(cars[i]->get_service_start_90_octane()-last_90_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                cars[i]->set_idle_time_gas(cars[i]->get_service_start_gas()-last_gas_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
            if(cars[i]->get_service_start_90_octane_2()!=-1)
            {
                cars[i]->set_idle_time_90_octane_2(cars[i]->get_service_start_90_octane_2()-last_90_octane_busy_time_2);
            }
            else
            {
                cars[i]->set_idle_time_90_octane_2(-1);
            }
        }

         //Determine the Fuel type for each car
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            cars[i]->set_fuel_type("95 Octane");
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_fuel_type("90 Octane");
        }
        else if(cars[i]->get_service_start_90_octane_2()!=-1)
        {
            cars[i]->set_fuel_type("90 Octane");
        }
        else
        {
            cars[i]->set_fuel_type("Gas");
        }


        //Updating last time busy for each pump
        if (cars[i]->get_service_start_95_octane()!=-1)
        {
            last_95_octane_busy_time=cars[i]->get_leave_time();
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            last_90_octane_busy_time=cars[i]->get_leave_time();
        }
        else if(cars[i]->get_service_start_90_octane_2()!=-1)
        {
            last_90_octane_busy_time_2=cars[i]->get_leave_time();
        }
        else
        {
            last_gas_busy_time=cars[i]->get_leave_time();
        }

        //Calculate waiting time for each pump
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            total_waiting_time_95+=(cars[i]->get_service_start_95_octane()-cars[i]->get_arrival_time());
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            total_waiting_time_90+=(cars[i]->get_service_start_90_octane()-cars[i]->get_arrival_time());
        }
        else if(cars[i]->get_service_start_90_octane_2()!=-1)
        {
            total_waiting_time_90_2+=(cars[i]->get_service_start_90_octane_2()-cars[i]->get_arrival_time());
        }
        else
        {
            total_waiting_time_gas+=(cars[i]->get_service_start_gas()-cars[i]->get_arrival_time());
        }

        //Clear the queues for each pump after the last car done
        if (i==num_cars_to_simulate-1)
        {
            while(!num_waiting_95_octane.empty())
            {
                num_waiting_95_octane.pop();
            }
            while(!num_waiting_90_octane.empty())
            {
                num_waiting_90_octane.pop();
            }
            while(!num_waiting_90_octane_2.empty())
            {
                num_waiting_90_octane_2.pop();
            }
            while(!num_waiting_gas.empty())
            {
                num_waiting_gas.pop();
            }
        }
     }

     //Update total and average waiting time for the simulation run
     total_waiting_time_all_cars=total_waiting_time_95+total_waiting_time_90+total_waiting_time_gas+total_waiting_time_90_2;
     average_waiting_time_all_cars_after_90_addition[k]=total_waiting_time_all_cars/(float)num_cars_to_simulate;


//Write table header to the output file
output_3<<endl<<"========================================================================= Table Number: "<<k+1<<" ========================================================================="<<endl;
output_3<<endl;


output_3<< setw(10) << "Car NO." << setw(12) << "Category" << setw(12) << "Arrival" << setw(12) << "Start 95"
       << setw(12) << "Start 90" << setw(15) << "start_90_2" << setw(15) << "Start Gas"
       << setw(12) << "Service" << setw(12) << "Leave" << setw(12) << "Idle 95"
       << setw(12) << "Idle 90" << setw(12) << "Idle 90_2" << setw(15) << "Idle Gas" << endl;

output_3<< setw(10) << "" << setw(12) << "" << setw(12) << "Time" << setw(12) << "Time"
       << setw(12) << "Time" << setw(15) << "Time" << setw(15) << "Time"
       << setw(12) << "Time" << setw(12) << "Time" << setw(12) << "Time"
       << setw(12) << "Time" << setw(12) << "Time" <<setw(11)<<"Time"<< endl;

output_3 << string(165, '=') << endl;

//Write car data to the table
for (int i=0;i<num_cars_to_simulate; i++)
    {
    output_3 << setw(10) << cars[i]->get_car_number()
           << setw(12) << cars[i]->get_car_category()
           << setw(12) << cars[i]->get_arrival_time()
           << setw(12) << (cars[i]->get_service_start_95_octane() == -1 ? "-" : to_string(cars[i]->get_service_start_95_octane()))
           << setw(12) << (cars[i]->get_service_start_90_octane() == -1 ? "-" : to_string(cars[i]->get_service_start_90_octane()))
           << setw(15)<<(cars[i]->get_service_start_90_octane_2() == -1 ? "-" : to_string(cars[i]->get_service_start_90_octane_2()))
           << setw(15) << (cars[i]->get_service_start_gas() == -1 ? "-" : to_string(cars[i]->get_service_start_gas()))
           << setw(12) << cars[i]->get_service_time()
           << setw(12) << cars[i]->get_leave_time()
           << setw(12) << (cars[i]->get_idle_time_95() == -1 ? "-" : to_string(cars[i]->get_idle_time_95()))
           << setw(12) << (cars[i]->get_idle_time_90() == -1 ? "-" : to_string(cars[i]->get_idle_time_90()))
           << setw(12) <<(cars[i]->get_idle_time_90_octane_2() == -1 ? "-" : to_string(cars[i]->get_idle_time_90_octane_2()))
           << setw(15) << (cars[i]->get_idle_time_gas() == -1 ? "-" : to_string(cars[i]->get_idle_time_gas())) <<endl;

    output_3 << string(165, '-') << endl;
}

output_3 << endl<<endl;;

}
output_3.close();

//Calculate the average waiting time for all cars from the extra 90 octane pump simulation run.
float sum_average_waiting_time_all_cars_after_90_addition=0;
for (int i=0;i<num_of_runs;i++)
{
    sum_average_waiting_time_all_cars_after_90_addition+=average_waiting_time_all_cars_after_90_addition[i];
}

//Open an text file for writing the simulation tables
ofstream output_4("Petrol Station Simulation Tables (Extra 95 Pump).txt");
    output_4<<"Simulation Summary:"<<endl;
    output_4<<"-------------------"<<endl;
    output_4<<"Number of Tables: "<<num_of_runs<<endl;
    output_4<<"Number of Cars Simulated per Table: "<<num_cars_to_simulate<<endl<<endl;

//Addition of an Extra 95 octane Pump
//Outer loop to Iterate through each simulation run
 for(int k=0;k<num_of_runs;k++)
{
    //Initialize variables for each run
    last_95_octane_busy_time=0;
    last_90_octane_busy_time=0;
    last_gas_busy_time=0;
    last_95_octane_busy_time_2=0;
    total_waiting_time_95=0;
    total_waiting_time_90=0;
    total_waiting_time_gas=0;
    total_waiting_time_95_2=0;
    total_waiting_time_all_cars=0;

        //Inner loop to Simulate each car
        for (int i=0;i<num_cars_to_simulate;i++)
     {
         //Set car number
        cars[i]->set_car_number(i+1);

        //Set time between arrivals
        if (i==0)
        {
           cars[i]->set_time_between_arrivals(-1);
        }
        else
        {
            cars[i]->set_time_between_arrivals(random_list_generate_time_between_arrivals[k][i]);
        }

        //Set arrival time
        if (i==0)
        {
            cars[i]->set_arrival_time(0);
        }
        else
        {
            cars[i]->set_arrival_time(cars[i]->get_time_between_arrivals()+cars[i-1]->get_arrival_time());
        }

        //Set car category
        cars[i]->set_car_category(random_list_generate_car_category[k][i]);

        //Set service time
        if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_a_b[k][i]);
        }
        else
        {
            cars[i]->set_service_time(random_list_generate_service_time_for_category_c[k][i]);
        }

        //Queues for 95, 90 Octane ,Gas and extra 95 octane pumps to remove completed cars
        while(!num_waiting_95_octane.empty()&&cars[num_waiting_95_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_95_octane.pop();
        }

        while(!num_waiting_90_octane.empty()&&cars[num_waiting_90_octane.front()]->get_leave_time()<= cars[i]->get_arrival_time())
        {
            num_waiting_90_octane.pop();
        }

        while(!num_waiting_gas.empty()&&cars[num_waiting_gas.front()]->get_leave_time()<=cars[i]->get_arrival_time())
        {
            num_waiting_gas.pop();
        }
        while(!num_waiting_95_octane_2.empty()&&cars[num_waiting_95_octane_2.front()]->get_leave_time()<=cars[i]->get_arrival_time())
        {
            num_waiting_95_octane_2.pop();
        }

        //Handle service start times for the 95 octane pump and the extra 95 octane pump.
        if (cars[i]->get_car_category()=='C')
        {
            cars[i]->set_service_start_95_octane(-1);
            cars[i]->set_service_start_95_octane_2(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (num_waiting_90_octane.size()>3&&(random_list_generate_going_to_95_pump_or_not[k][i]>0&&random_list_generate_going_to_95_pump_or_not[k][i]<=0.6))
            {
                if (num_waiting_95_octane.size()<=num_waiting_95_octane_2.size())
                {
                    num_waiting_95_octane.push(i);
                    cars[i]->set_service_start_95_octane_2(-1);
                    if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                    {
                            cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                    }
                }
                else
                {
                    num_waiting_95_octane_2.push(i);
                    cars[i]->set_service_start_95_octane(-1);
                    if (cars[i]->get_arrival_time()>=last_95_octane_busy_time_2)
                    {
                            cars[i]->set_service_start_95_octane_2(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_95_octane_2(last_95_octane_busy_time_2);
                    }
                }
            }
            else
            {
                cars[i]->set_service_start_95_octane(-1);
                cars[i]->set_service_start_95_octane_2(-1);
            }
        }
        else
        {
            if (num_waiting_95_octane.size()<=num_waiting_95_octane_2.size())
                {
                    num_waiting_95_octane.push(i);
                    cars[i]->set_service_start_95_octane_2(-1);
                    if (cars[i]->get_arrival_time()>=last_95_octane_busy_time)
                    {
                            cars[i]->set_service_start_95_octane(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_95_octane(last_95_octane_busy_time);
                    }
                }
                else
                {
                    num_waiting_95_octane_2.push(i);
                    cars[i]->set_service_start_95_octane(-1);
                    if (cars[i]->get_arrival_time()>=last_95_octane_busy_time_2)
                    {
                            cars[i]->set_service_start_95_octane_2(cars[i]->get_arrival_time());
                    }
                    else
                    {
                        cars[i]->set_service_start_95_octane_2(last_95_octane_busy_time_2);
                    }
                }
        }

        //Handle service start times for 90 octane pump
        if (cars[i]->get_car_category()=='A')
        {
            cars[i]->set_service_start_90_octane(-1);
        }
        else if (cars[i]->get_car_category()=='B')
        {
            if (cars[i]->get_service_start_95_octane()!=-1||cars[i]->get_service_start_95_octane_2()!=-1)
            {
                cars[i]->set_service_start_90_octane(-1);
            }
            else
            {
                num_waiting_90_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                {
                    cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                }
            }
        }
        else
        {
            if (num_waiting_gas.size()>4&&(random_list_generate_going_to_90_pump_or_not[k][i]>0&&random_list_generate_going_to_90_pump_or_not[k][i]<=0.4))
            {
                num_waiting_90_octane.push(i);
                if (cars[i]->get_arrival_time()>=last_90_octane_busy_time)
                {
                    cars[i]->set_service_start_90_octane(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_90_octane(last_90_octane_busy_time);
                }
            }
            else
            {
                cars[i]->set_service_start_90_octane(-1);
            }
        }


        //Handle service start times for Gas pump
         if (cars[i]->get_car_category()=='A'||cars[i]->get_car_category()=='B')
        {
            cars[i]->set_service_start_gas(-1);
        }
        else
        {
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                cars[i]->set_service_start_gas(-1);
            }
            else
            {
                num_waiting_gas.push(i);
                if (cars[i]->get_arrival_time()>=last_gas_busy_time)
                {
                    cars[i]->set_service_start_gas(cars[i]->get_arrival_time());
                }
                else
                {
                    cars[i]->set_service_start_gas(last_gas_busy_time);
                }
            }
        }

        //Set leave time based on the pump used
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_95_octane()+cars[i]->get_service_time());
        }
        else if (cars[i]->get_service_start_95_octane_2()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_95_octane_2()+cars[i]->get_service_time());
        }
        else if (cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_90_octane()+cars[i]->get_service_time());
        }
        else
        {
            cars[i]->set_leave_time(cars[i]->get_service_start_gas()+cars[i]->get_service_time());
        }


        //Calculate idle time for each pump
         if (i==0)
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                 cars[i]->set_idle_time_95(0);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                 cars[i]->set_idle_time_90(0);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                 cars[i]->set_idle_time_gas(0);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
            if (cars[i]->get_service_start_95_octane_2()!=-1)
            {
                cars[i]->set_idle_time_95_octane_2(0);
            }
            else
            {
                cars[i]->set_idle_time_95_octane_2(-1);
            }
        }
        else
        {
            if (cars[i]->get_service_start_95_octane()!=-1)
            {
                cars[i]->set_idle_time_95(cars[i]->get_service_start_95_octane()-last_95_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_95(-1);
            }
            if (cars[i]->get_service_start_90_octane()!=-1)
            {
                cars[i]->set_idle_time_90(cars[i]->get_service_start_90_octane()-last_90_octane_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_90(-1);
            }
            if (cars[i]->get_service_start_gas()!=-1)
            {
                cars[i]->set_idle_time_gas(cars[i]->get_service_start_gas()-last_gas_busy_time);
            }
            else
            {
                cars[i]->set_idle_time_gas(-1);
            }
            if(cars[i]->get_service_start_95_octane_2()!=-1)
            {
                cars[i]->set_idle_time_95_octane_2(cars[i]->get_service_start_95_octane_2()-last_95_octane_busy_time_2);
            }
            else
            {
                cars[i]->set_idle_time_95_octane_2(-1);
            }
        }


        //Determine the Fuel type for each car
        if(cars[i]->get_service_start_95_octane()!=-1||cars[i]->get_service_start_95_octane_2()!=-1)
        {
            cars[i]->set_fuel_type("95 Octane");
        }
        else if (cars[i]->get_service_start_90_octane()!=-1)
        {
            cars[i]->set_fuel_type("90 Octane");
        }
        else
        {
            cars[i]->set_fuel_type("Gas");
        }

        //Updating last time busy for each pump
        if (cars[i]->get_service_start_95_octane()!=-1)
        {
            last_95_octane_busy_time=cars[i]->get_leave_time();
        }
        else if(cars[i]->get_service_start_95_octane_2()!=-1)
        {
            last_95_octane_busy_time_2=cars[i]->get_leave_time();
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            last_90_octane_busy_time=cars[i]->get_leave_time();
        }
        else
        {
            last_gas_busy_time=cars[i]->get_leave_time();
        }

        //Calculate waiting time for each pump
        if(cars[i]->get_service_start_95_octane()!=-1)
        {
            total_waiting_time_95+=(cars[i]->get_service_start_95_octane()-cars[i]->get_arrival_time());
        }
        else if (cars[i]->get_service_start_95_octane_2()!=-1)
        {
            total_waiting_time_95_2+=(cars[i]->get_service_start_95_octane_2()-cars[i]->get_arrival_time());
        }
        else if(cars[i]->get_service_start_90_octane()!=-1)
        {
            total_waiting_time_90+=(cars[i]->get_service_start_90_octane()-cars[i]->get_arrival_time());
        }
        else if(cars[i]->get_service_start_gas()!=-1)
        {
            total_waiting_time_gas+=(cars[i]->get_service_start_gas()-cars[i]->get_arrival_time());
        }


        //Clear the queues for each pump after the last car done
        if (i==num_cars_to_simulate-1)
        {
            while(!num_waiting_95_octane.empty())
            {
                num_waiting_95_octane.pop();
            }
            while(!num_waiting_90_octane.empty())
            {
                num_waiting_90_octane.pop();
            }
            while(!num_waiting_gas.empty())
            {
                num_waiting_gas.pop();
            }
            while(!num_waiting_95_octane_2.empty())
            {
                num_waiting_95_octane_2.pop();
            }
        }
     }


     //Update total and average waiting time for the simulation run
     total_waiting_time_all_cars=total_waiting_time_95+total_waiting_time_90+total_waiting_time_gas+total_waiting_time_95_2;
     average_waiting_time_all_cars_after_95_addition[k]=total_waiting_time_all_cars/(float)num_cars_to_simulate;


//Write table header to the output file
output_4<<endl<<"========================================================================= Table Number: "<<k+1<<" ========================================================================="<<endl;
output_4<<endl;

output_4<< setw(10) << "Car NO." << setw(12) << "Category" << setw(12) << "Arrival" << setw(12) << "Start 95"
       << setw(15) << "Start 95_2" << setw(15) << "start_90" << setw(15) << "Start Gas"
       << setw(12) << "Service" << setw(12) << "Leave" << setw(12) << "Idle 95"
       << setw(12) << "Idle 95_2" << setw(12) << "Idle 90" << setw(15) << "Idle Gas" << endl;

output_4<< setw(10) << "" << setw(12) << "" << setw(12) << "Time" << setw(12) << "Time"
       << setw(15) << "Time" << setw(15) << "Time" << setw(15) << "Time"
       << setw(12) << "Time" << setw(12) << "Time" << setw(12) << "Time"
       << setw(12) << "Time" << setw(12) << "Time" <<setw(15)<<"Time"<< endl;

output_4 << string(165, '=') << endl;

//Write car data to the table
for (int i=0;i<num_cars_to_simulate; i++)
    {
    output_4 << setw(10) << cars[i]->get_car_number()
           << setw(12) << cars[i]->get_car_category()
           << setw(12) << cars[i]->get_arrival_time()
           << setw(12) << (cars[i]->get_service_start_95_octane() == -1 ? "-" : to_string(cars[i]->get_service_start_95_octane()))
           << setw(15)<<(cars[i]->get_service_start_95_octane_2() == -1 ? "-" : to_string(cars[i]->get_service_start_95_octane_2()))
           << setw(15) << (cars[i]->get_service_start_90_octane() == -1 ? "-" : to_string(cars[i]->get_service_start_90_octane()))
           << setw(15) << (cars[i]->get_service_start_gas() == -1 ? "-" : to_string(cars[i]->get_service_start_gas()))
           << setw(12) << cars[i]->get_service_time()
           << setw(12) << cars[i]->get_leave_time()
           << setw(12) << (cars[i]->get_idle_time_95() == -1 ? "-" : to_string(cars[i]->get_idle_time_95()))
           << setw(12) <<(cars[i]->get_idle_time_95_octane_2() == -1 ? "-" : to_string(cars[i]->get_idle_time_95_octane_2()))
           << setw(12) << (cars[i]->get_idle_time_90() == -1 ? "-" : to_string(cars[i]->get_idle_time_90()))
           << setw(14) << (cars[i]->get_idle_time_gas() == -1 ? "-" : to_string(cars[i]->get_idle_time_gas())) <<endl;

    output_4 << string(165, '-') << endl;
}

output_4 << endl;

}
output_4.close();


//Calculate the average waiting time for all cars from the extra 95 octane pump simulation run.
float sum_average_waiting_time_all_cars_after_95_addition=0;
for (int i=0;i<num_of_runs;i++)
{
    sum_average_waiting_time_all_cars_after_95_addition+=average_waiting_time_all_cars_after_95_addition[i];
}



//Results of Adding Extra Pumps
cout <<"\n============ Results of Adding Extra Pumps ============\n";

cout <<"1. Adding one extra Gas pump:\n";
cout <<"   Average Waiting Time for all cars: "
     <<sum_average_waiting_time_all_cars_after_gas_addition / (float)num_of_runs
     <<" mins/car\n";

cout <<"\n2. Adding one extra 90 Octane pump:\n";
cout <<"   Average Waiting Time for all cars: "
     <<sum_average_waiting_time_all_cars_after_90_addition / (float)num_of_runs
     <<" mins/car\n";

cout <<"\n3. Adding one extra 95 Octane pump:\n";
cout <<"   Average Waiting Time for all cars: "
     <<sum_average_waiting_time_all_cars_after_95_addition / (float)num_of_runs
     <<" mins/car\n";

//Determine the best pump addition
cout<<"\n--- Recommendation ---\n";

if ((sum_average_waiting_time_all_cars_after_gas_addition / (float)num_of_runs) <
    (sum_average_waiting_time_all_cars_after_90_addition / (float)num_of_runs) &&
    (sum_average_waiting_time_all_cars_after_gas_addition / (float)num_of_runs) <
    (sum_average_waiting_time_all_cars_after_95_addition / (float)num_of_runs))
{
    cout<<"Adding one extra Gas pump will result in the greatest decrease "
         <<"in the average waiting time for all cars compared to adding any other type of pump."<<endl;
}
else if ((sum_average_waiting_time_all_cars_after_90_addition / (float)num_of_runs) <
         (sum_average_waiting_time_all_cars_after_gas_addition / (float)num_of_runs) &&
         (sum_average_waiting_time_all_cars_after_90_addition / (float)num_of_runs) <
         (sum_average_waiting_time_all_cars_after_95_addition / (float)num_of_runs))
{
    cout<<"Adding one extra 90 Octane pump will result in the greatest decrease "
         <<"in the average waiting time for all cars compared to adding any other type of pump."<<endl;
}
else
{
    cout<<"Adding one extra 95 Octane pump will result in the greatest decrease "
         <<"in the average waiting time for all cars compared to adding any other type of pump."<<endl;
}

cout<<"\n============================================================================================================================="
        "=======================\n";

cout<<"\t\t\t\t<<<Please review the four text files to examine the tables from the simulation runs.>>>"<<endl;


//Run the Python script to visualize the 3 Main Pumps
ofstream batch_file("run_python.bat");
batch_file<<"python \"D:\\\\Petrol Station Multi-Channel Queue\\\\Visualize_Simulation (Three Main Pumps).py\""<<endl;
batch_file.close();
system("start /min run_python.bat");


//Deleting the memory allocated for the car objects
for (int i=0;i<num_cars_to_simulate;i++)
    {
        delete cars[i];
    }
//Deleting the memory allocated for random data used in the simulation
for (int i=0;i<num_of_runs;i++)
    {
        delete[] random_list_generate_car_category[i];
        delete[] random_list_generate_time_between_arrivals[i];
        delete[] random_list_generate_service_time_for_category_a_b[i];
        delete[] random_list_generate_service_time_for_category_c[i];
        delete[] random_list_generate_going_to_95_pump_or_not[i];
        delete[] random_list_generate_going_to_90_pump_or_not[i];
    }

        //Deleting the memory allocated for arrays storing simulation results and statistics
        delete[] list_total_simulation_run_time;
        delete[] average_service_time_95;
        delete[] average_service_time_90;
        delete[] average_service_time_gas;
        delete[] average_service_time_category_a;
        delete[] average_service_time_category_b;
        delete[] average_service_time_category_c;
        delete[] average_waiting_time_95;
        delete[] average_waiting_time_90;
        delete[] average_waiting_time_gas;
        delete[] average_waiting_time_all_cars;
        delete[] list_max_queue_length_95;
        delete[] list_max_queue_length_90;
        delete[] list_max_queue_length_gas;
        delete[] probability_car_waits_95;
        delete[] probability_car_waits_90;
        delete[] probability_car_waits_gas;
        delete[] probability_idle_time_95;
        delete[] probability_idle_time_90;
        delete[] probability_idle_time_gas;
        delete[] average_waiting_time_all_cars_after_gas_addition;
        delete[] average_waiting_time_all_cars_after_90_addition;
        delete[] average_waiting_time_all_cars_after_95_addition;
        delete[] values_time_between_arrivals;
        delete[] probabilities_time_between_arrivals;
        delete[] values_category_a_b_service_time;
        delete[] probabilities_category_a_b_service_time;
        delete[] values_category_c_service_time;
        delete[] probabilities_category_c_service_time;

    return 0;
}
