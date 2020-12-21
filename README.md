# Linux-Covid19-Statistics-Data
a bash program that retrieves statistics for each country (except USA) in the world using REST API (postman.com) and 3 c functions to showcase data.
the data is collected from https://documenter.getpostman.com/view/10808728/SzS8rjbc
to run:

1. move all files to the same directory and cd to directory path
2. make sure all file have permissions (chmod 755 *) and run: 
3.      ./getByCountry.sh
4.      make
5.      export LD_LIBRARY_PATH=`pwd`

- to Print a country's “graph” according to key type: 

      ./print_graph.o --key <Active/Death/Recovered/Confirmed> --country <country name>
      
- to Print all countries specific data according to date type: 

      ./print_by_date.o --date <yyyy-MM-dd> --key <Active/Death/Recovered/Confirmed>
      
- to Export data by country to CSV type: 

      ./country_data_to_csv.o --country <country name>
        
(to clean all compiltion products run: make clean)
