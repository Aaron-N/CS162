/*********************************************************************
** Program name:  Project 2 (Zoo.cpp)
** Author:        Aaron Nesbit
** Date:          10/22/19
** Description:   This is the implementation file for the class Zoo
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"
#include "input_validation.hpp"

using std::srand;
using std::time;
using std::cout;
using std::endl;
using std::exit;

/*
* Summary: Default constructor
*/
Zoo::Zoo()
{
   tigers = new Animal *[10];     // Tiger array created
   penguins = new Animal *[10];   // Penguin array created
   turtles = new Animal *[10];    // Turtle array created
   tiger_array_size = 10;         // Initial tiger array size set
   penguin_array_size = 10;       // Initial penguin array size set
   turtle_array_size = 10;        // Initial turtle array size set
   bank = 25000;                 // Initial bank balance set
   attendance_bonus = 0;          // Initial attandance bonus set

   // Array elements set to NULL as there are no animals yet
   for(int i = 0; i < 10; i++)
   {
      tigers[i] = 0;
      penguins[i] = 0;
      turtles[i] = 0;
   }
}

/*
* Summary: Destructor
*/
Zoo::~Zoo(){}

/*
* Summary: add_animal(Animal *a) - adds an animal to array by checking
*          the animal type and then runs the appropriate add function 
*/
void Zoo::add_animal(Animal *a)
{
   if(a->get_type() == "Tiger")         // If new animal is tiger
   {
      add_tiger(a);                     // Tiger added
   }
   else if(a->get_type() == "Penguin")  // If new animal is penguin
   {
      add_penguin(a);                   // Penguin added
   }
   else if(a->get_type() == "Turtle")   // If new animal is turtle
   {
      add_turtle(a);                    // Turtle added
   }
}

/*
* Summary:    is_array_full() - checks if an array is full. Checks each
*             element to see if something is there. If array is empty,
*             it returns false. If array is not empty, it returns true.
* Parameters: Pointer to an array of pointers
*             Array size
*/
bool Zoo::is_array_full(Animal **a, int size)
{
   for(int i = 0; i < size; i++)
   {
      if(!a[i])
      {
         return false;
      }
   }
   return true;
}

/*
* Summary: resize_array()- resizes dynamic animal array by doubling its
*          size and deleting old array
* Parameters: Pointer to an array of pointers
*             Array size passed by reference
*/
void Zoo::resize_array(Animal **&a, int &size)
{
   Animal **new_array = new Animal *[size * 2];

   // Set each element in new array to NULL
   for(int i = 0; i < size * 2; i++)
   {
      new_array[i] = NULL;
   }

   // Copy old array into new array
   for(int i = 0; i < size; i++)
   {
      new_array[i] = a[i];
   }
   
   // Old array deleted
   delete [] a;

   // Set new array
   a = new_array;
   
   // Update size of array
   size = size * 2;
}

/*
* Summary: add_tiger(Animal *a) - checks the tiger array to see if it
*          is full, if it is, it doubles array size and then adds tiger.
*          If array not full, just adds tiger.
* Parameter: Pointer to array         
* Returns: Pointer
*/
void Zoo::add_tiger(Animal *a)
{
   if(is_array_full(tigers, tiger_array_size))   // Is array full?
   {
      resize_array(tigers, tiger_array_size);    // If yes, double size
   }

   for(int i = 0; i < tiger_array_size; i++)     // Adds a tiger
   {
      if(tigers[i] == NULL)
      {
      tigers[i] = a;
      break;
      }
   }
}

/*
* Summary: add_penguin(Animal *a) - checks the penguin array to see if it
*          is full, if it is, it doubles array size and then adds penguin.
*          If array not full, just adds penguin.
* Parameter: Pointer to array         
* Returns: Pointer
*/
void Zoo::add_penguin(Animal *a)
{
   if(is_array_full(penguins, penguin_array_size)) // Is array full?
   {
      resize_array(penguins, penguin_array_size);  // If yes, double size
   }

   for(int i = 0; i < penguin_array_size; i++)   // Adds a penguin
   {
      if(penguins[i] == NULL)
      {
      penguins[i] = a;
      break;
      }
   }
}

/*
* Summary: add_turtle(Animal *a) - checks the turtle array to see if it
*          is full, if it is, it doubles array size and then adds turtle.
*          If array not full, just adds turtle.
* Parameter: Pointer to array         
* Returns: Pointer
*/
void Zoo::add_turtle(Animal *a)
{
   if(is_array_full(turtles, turtle_array_size)) // Is array full?
   {
      resize_array(turtles, turtle_array_size);  // If yes, double size
   }

   for(int i = 0; i < turtle_array_size; i++)    // Adds a turtle
   {
      if(turtles[i] == NULL)
      {
      turtles[i] = a;
      break;
      }
   }
}

/*
* Summary: print_animals() - prints out details of each animal array
*          by animal type
*/
void Zoo::print_animals()
{
   cout << "Animals in the Zoo: " << endl;
   int i = 0;                            // Iterator set
   int num_tigers = 0;                   // Initial tiger count set
   int num_penguins = 0;                 // Initial penguin count set
   int num_turtles = 0;                  // Initial turtle count set

   while(tigers[i] != NULL)              // Tigers counted
   {
      num_tigers++;
      i++;
   }

   i = 0;                                // Iterator reset
   while(penguins[i] != NULL)            // Penguins counted
   {
      num_penguins++;
      i++;
   }

   i = 0;                                // Iterator rest
   while(turtles[i] != NULL)             // Turtles counted
   {
      num_turtles++;
      i++;
   }

   // Animals totals displayed
   cout << "Tigers: " << num_tigers << endl;
   cout << "Penguins: " << num_penguins << endl;
   cout << "Turtles: " << num_turtles << endl;
}


/*
* Summary: play_game() - this is the main game loop
*/
void Zoo::play_game()
{
   int choice;
   srand(time(NULL));    // For random events in game
 
   // User chooses to play or quit
   cout << "Welcome to Zoo Tycoon!" << endl;
   cout << "1. Play game" << endl;
   cout << "2. Exit game" << endl;

   choice = int_validate_2_choice();        // Input validated

   if(choice == 2)           // If user chooses to quit
   {   
      delete_arrays();       // Arrays deleted
      cout << "Goodbye!" << endl;
      exit(0);
   }

   // If user chooses to play, enter game
   buy_animal_menu();

   // Initiate variables for daily values
   int day_count = 1;
   int food_cost = 0;
   int profit = 0;

   // The main game loop
   while(true)
   {
      cout << "------------------------------" << endl;
      cout << "Day " << day_count << ": " << endl;

      // Reset attendance bonus and profit each day
      attendance_bonus = 0;
      profit = 0;

      // Current animal inventory displayed
      print_animals();

      // Age animals 1 day
      age_all_animals();

      // Calculate and subtract feeding costs from bank account
      food_cost = calc_feeding_costs();
      make_payment(food_cost);
      cout << "It costs $" << calc_feeding_costs() << " to feed your "
           << "animals today. You have $" << get_bank_balance() 
           << " remaining." << endl;

      // Check for random event
      cout << "Rolling for random event..." << endl;
      random_event();

      // Display daily summary
      cout << "Daily summary: " << endl;
      cout << "Payoff from animals: $" << calc_payoff() << endl;
      cout << "Feeding costs:       $" << calc_feeding_costs() << endl;

      if(attendance_bonus != 0) // If attendance bonus occured
      {
         profit = ((calc_payoff() - calc_feeding_costs()) +
                  attendance_bonus);
         cout << "Bonus from boom in attendance: $" << attendance_bonus
              << endl;
         cout << "Profits for the day: $" << profit << endl;
      }
      else                   // If attendance bonus did not occur
      {
         profit = (calc_payoff() - calc_feeding_costs());
         cout << "Profits for the day: $" << profit << endl;
      }

      // Deposit profit for day into bank account
      get_paid(profit);

      // Display updated bank account balance
      cout << "New bank balance: $" << get_bank_balance() << endl;

      // Check to see if user has  money in bank account
      // if not, the game ends
      if(get_bank_balance() <= 0)
      {
         delete_arrays();    // Arrays deleted
         cout << "You're out of money so the Zoo is closed!" << endl;
         cout << "Goodbye!" << endl;
         exit(0);
      } 

      // Ask user if they want to buy an adult animal
      buy_adult_animal();

      // Ask user if they want to keep playing or quit
      cout << "Do you want to keep playing?" << endl;
      cout << "1. Yes" << endl;
      cout << "2. No" << endl;

      choice = int_validate_2_choice();     // Input validated

      // If user chooses to quit, exit game
      if(choice == 2)
      {
         delete_arrays();     // Arrays deleted
         cout << "Goodbye!" << endl;
         exit(0);
      }

      // Add one to day counter
      day_count++;
   }
}


/*
* Summary: get_bank_balance() - gets bank account balance
* Returns: bank account balance
*/
int Zoo::get_bank_balance()
{
   return bank;              // Current bank balance returned
}


/*
* Summary: make_payment() - subtracts payment money from bank account
* Parameters: payment to subtract from account
*/
void Zoo::make_payment(int m)
{
   bank = bank - m;          // Payment subtracted from bank balance
}


/*
* Summary: get_paid() - adds payment money to bank account
* Parameters: payment to be added to account
*/
void Zoo::get_paid(int m)
{
   bank = bank + m;          // Payment added to bank balance
}


/*
* Summary: buy_animal_menu() - menu for handling purchases for animals
*          at the start of the game
*/
void Zoo::buy_animal_menu()
{
   cout << "You must buy at least one of each animal" << endl;
   buy_tiger_menu();       // Tiger purchase menu initiated
   buy_penguin_menu();     // Penguin purchase menu initiated
   buy_turtle_menu();      // Turtle purchase menu initiated
}

/*
* Summary: buy_tiger_menu() - menu for handling purchase of tigers at
*          the start of the game
*/
void Zoo::buy_tiger_menu()
{
   int choice;

   cout << "Tigers are $10,000. You currently have $" << get_bank_balance()
        << " in your account" << endl;
   cout << "How many would you like to buy?" << endl;
   cout << "1" << endl;
   cout << "2" << endl;

   choice = int_validate_2_choice();        // Input validated

   if(choice == 1)           // One tiger purchased
   {
      make_payment(10000);
      cout << "You bought one tiger for $10,000. You have $"
           << get_bank_balance() << " remaining." << endl;
      add_animal(new Tiger(1));
   }
   else if(choice == 2)      // Two tigers purchased
   {
      make_payment(20000);
      cout << "You bought two tigers for $20,000. You have $"
           << get_bank_balance() << " remaining." << endl;
      add_animal(new Tiger(1));
      add_animal(new Tiger(1));
   }
   cout << "------------------------------" << endl;
}


/*
* Summary: buy_penguin_menu() - menu for purchase of penguins at
*          the start of the game
*/
void Zoo::buy_penguin_menu()
{
   int choice;

   cout << "Penguins are $1,000. You currently have $" << get_bank_balance()
        << " in your account" << endl;
   cout << "How many would you like to buy?" << endl;
   cout << "1" << endl;
   cout << "2" << endl;

   choice = int_validate_2_choice();        // Input validated

   if(choice == 1)           // One penguin purchased
   {
      make_payment(1000);
      cout << "You bought one penguin for $1,000. You have $"
           << get_bank_balance() << " remaining." << endl;
      add_animal(new Penguin(1));
   }
   else if(choice == 2)      // Two penguins purchased
   {
      make_payment(2000);
      cout << "You bought two penguins for $2,000. You have $"
           << get_bank_balance() << " remaining." << endl;
      add_animal(new Penguin(1));
      add_animal(new Penguin(1));
   }
   cout << "------------------------------" << endl;
}


/*
* Summary: buy_turtle_menu() - menu for purchase of turtles at
*          the start of the game
*/
void Zoo::buy_turtle_menu()
{
   int choice;

   cout << "Turtles are $100. You currently have $" << get_bank_balance()
        << " in your account" << endl;
   cout << "How many would you like to buy?" << endl;
   cout << "1" << endl;
   cout << "2" << endl;

   choice = int_validate_2_choice();        // Input validated

   if(choice == 1)           // One turle purchased
   {
      make_payment(100);
      cout << "You bought one turtle for $100. You have $"
           << get_bank_balance() << " remaining." << endl;
      add_animal(new Turtle(1));
   }
   else if(choice == 2)      // Two turtles purchased
   {
      make_payment(200);
      cout << "You bought two turtles for $200. You have $"
           << get_bank_balance() << " remaining." << endl;
      add_animal(new Turtle(1));
      add_animal(new Turtle(1));
   }
   cout << "------------------------------" << endl;
}


/*
* Summary: age_all_animals() - increases the ages of all animals in
*          the zoo by one day
*/
void Zoo::age_all_animals()
{
   int i = 0;
   while(tigers[i] != NULL)
   {
      tigers[i]->age_one_day();       // All tigers aged on day
      i++;
   }
 
   i = 0;
   while(penguins[i] != NULL)
   {
      penguins[i]->age_one_day();     // All penguins aged one day
      i++;
   }
  
   i = 0;
   while(turtles[i] != NULL)
   {
      turtles[i]->age_one_day();      // All turtles aged one day
      i++;
   }
}

/*
* Summary: calc_feeding_costs() - calculates the total cost of feeding
*          all the animals for the day
* Returns: total cost of feeding all animals
*/
int Zoo::calc_feeding_costs()
{
   int i = 0;
   int total_cost = 0;                 // Initial food cost total set

   while(tigers[i] != NULL)            // Checks for tigers
   {
      total_cost += tigers[i]->get_base_food_cost();  // Tiger food cost
      i++;                                            // calculated
   }

   i = 0;
   while(penguins[i] != NULL)          // Checks for penguins
   {
      total_cost += penguins[i]->get_base_food_cost();// Penguin food cost
      i++;                                            // calculated and
   }                                                  // added to total

   i = 0;
   while(turtles[i] != NULL)           // Checks for turtles
   {
      total_cost += turtles[i]->get_base_food_cost(); // Turtle food cost
      i++;                                            // calculated and
   }                                                  // added to total

   return total_cost;        // Total food cost for all animals returned
}


/*
* Summary: random_event() - checks for a daily random event
*/
void Zoo::random_event()
{
   int roll = (rand() % 4 + 1);   // Random event rolled
   
   switch(roll)
   {
      case 1:   // An animal gets sick and dies
         cout << "Random event!" << endl;
         cout << "An animal has gotten sick!" << endl;
         sick_animal();
         break;

      case 2:   // An attendance boom occurs
         cout << "Random event!" << endl;
         cout << "A boom in attendance!" << endl;
         attendance_boom();
         break;
   
      case 3:   // Baby animal(s) born
         cout << "Random event!" << endl;
         cout << "A baby is born!" << endl;
         baby_born();
         break;

      case 4:   // Nothing happens for the day
         cout << "Nothing happened today!" << endl;
         break;
   }
}


/*
* Summary: sick_animal() - a random animal gets sick and dies
*/
void Zoo::sick_animal()
{
   int roll = (rand() % 3 + 1);   // Random animal rolled

   switch(roll)
   {
      case 1:      // Tiger gets sick
         if(tigers[0] == NULL) // If no tigers, display message
         {
            cout << "A tiger sickness has spread, but there are "
                 << "currently no tigers." << endl;
            break;
         }
         else // Kill a tiger
         {
            cout << "A tiger has died." << endl;
            tiger_dies();
         }
         break;

      case 2:      // Penguin gets sick
         if(penguins[0] == NULL) // If no penguins, display message
         {
            cout << "A penguin sickness has spread, but there are "
                 << "currently no penguins." << endl;
            break;
         }
         else // Kill a penguin
         {
            cout << "A penguin has died." << endl;
            penguin_dies();
         }
         break;

      case 3:      // Turtle gets sick
         if(turtles[0] == NULL) // If no turtles, display message
         {
            cout << "A turtle sickness has spread, but there are "
                 << "currently no turtles." << endl;
            break;
         }
         else // Kill a turtle
         {
            cout << "A turtle has died." << endl;
            turtle_dies();
         }
         break;
   }
}


/*
* Summary: attendance_boom() - more people come to the zoo so ticket
*          sales increase and bonus is earned when there are tigers
*/
void Zoo::attendance_boom()
{
   int i = 0;
   int total_tigers = 0;               // Tiger count reset to zero 
   int bonus = 0;                      // Bonus reset to zero

   // Count tigers
   while(tigers[i] != NULL)
   {
      i++;
      total_tigers = i;
   }

   // if there is at least one tiger, bonus is calculated
   if(total_tigers != 0)
   {
      // Bonus between 250-500 dollars randomly generated
      int roll = (rand() % 250 +1) + 250;

      bonus = total_tigers * roll;
      
      cout << "There was a boom in zoo attendance today! Your "
           << total_tigers << " tiger(s) earned you an extra $"
           << bonus << "!" << endl;

      // Add bonus money to bank account
      get_paid(bonus);

      // Set bonus to be used in main game loop
      attendance_bonus = bonus;
   }
   else  // If there are no tigers, the following is displayed
   {
      cout << "There was a boom in attendance today, but you have no "
           << "tigers, unfortunately." << endl;
   }
}


/*
* Summary: baby_born() - a random animal has a baby
*/
void Zoo::baby_born()
{
   int roll = (rand() % 3 + 1);   // Random baby animal rolled
   int i = 0;
   bool born = false;   // Tracks if babies were born successfully

   switch(roll)
   {
      case 1:      // Tiger is born
         // Check if there are tigers at least 3 days old to have baby
         while(tigers[i] != NULL) 
         {
            if(tigers[i]->get_age() >= 3) // If there are, baby born
            {
               cout << "A baby tiger was born!" << endl;
               add_animal(new Tiger(0)); // Add baby tiger, age 0
               born = true;
               break;
            }
            i++;
         }
         
         // If no tigers at least 3 days old, no baby born
         if(!born)
         {
            cout << "There are no tigers old enough to have a baby."
                 << endl;      
         }
         break;
      case 2:      // Penguins are born
         // Check if there are penguins at least 3 days old to have babies
         while(penguins[i] != NULL) 
         {
            if(penguins[i]->get_age() >= 3) // If there are, babies born
            {
               cout << "5 baby penguins were born!" << endl;
               for(int i = 0; i < 5; i++)
               {
                  add_animal(new Penguin(0)); // Add 5 baby penguins, age 0
               }
               born = true;
               break;
            }
            i++;
         }
         
         // If no penguins at least 3 days old, no babies born
         if(!born)
         {
            cout << "There are no penguins old enough to have babies."
                 << endl;
         }
         break;
      case 3:      // Turtles are born
         // Check if there are turtles at least 3 days old to have babies
         while(turtles[i] != NULL) 
         {
            if(turtles[i]->get_age() >= 3) // If there are, babies born
            {
               cout << "10 baby turtles were born!" << endl;
               for(int i = 0; i < 10; i++)
               {
                  add_animal(new Turtle(0)); // Add 10 baby turtles, age 0
               }
               born = true;
               break;
            }
            i++;
         }
         
         // If no turtles at least 3 days old, no babies born
         if(!born)
         {
            cout << "There are no turtles old enough to have babies."
                 << endl;
         }
         break;
   }
}


/*
* Summary: tiger_dies() - a tiger dies and is removed from the array
*/
void Zoo::tiger_dies()
{
   int last_index;
   int i = 0;

   while(tigers[i] != NULL)
   {
      last_index = i;
      i++;
   }
  
   delete tigers[i - 1];     // Tiger removed from array
   tigers[i - 1] = NULL;
}


/*
* Summary: penguin_dies() - a penguin dies and is removed from the array
*/
void Zoo::penguin_dies()
{
   int last_index;
   int i = 0;

   while(penguins[i] != NULL)
   {
      last_index = i;
      i++;
   }
  
   delete penguins[i - 1];   // Penguin removed from array
   penguins[i - 1] = NULL;
}


/*
* Summary: turtle_dies() - a turtle dies and is removed from the array
*/
void Zoo::turtle_dies()
{
   int last_index;
   int i = 0;

   while(turtles[i] != NULL)
   {
      last_index = i;
      i++;
   }
  
   delete turtles[i - 1];    // Turtle removed from array
   turtles[i - 1] = NULL;
}


/*
* Summary: buy_adult_animal() - user asked if they would like to buy 
*          adult animal
*/
void Zoo::buy_adult_animal()
{
   int choice;

   // User asked if they would like to buy adult animal
   cout << "Would you like to buy a adult animal?" << endl;
   cout << "1. Yes" << endl;
   cout << "2. No" << endl;

   choice = int_validate_2_choice();        // Input validated
    
   if(choice == 1) // If yes, display purchasing menu
   {
      cout << "What type of animal do you want to buy?" << endl;
      cout << "1. Tiger" << endl;
      cout << "2. Penguin" << endl;
      cout << "3. Turtle" << endl;

      choice = int_validate_3_choice();     // Input validated

      switch(choice)
      {
         case 1:   // Tiger chosen
            if(get_bank_balance() < 10000) // If user cant afford tiger
            {
               cout << "You don't have enough money to buy a tiger "
                    << "right now. They cost $10,000 and you only have $"
                    << get_bank_balance() << endl;
            }  
            else   //Tiger purchased
            {
               make_payment(10000); // Subtract tiger cost from bank
               cout << "Tiger purchased for $10,000. You have $" 
                    << get_bank_balance() << " remaining." << endl;
               add_animal(new Tiger(3)); // Add adult tiger to array
            }
            break;

         case 2:   // Penguin chosen
            if(get_bank_balance() < 1000) // If user cant afford penguin
            {
               cout << "You don't have enough money to buy a penguin "
                    << "right now. They cost $1,000 and you only have $"
                    << get_bank_balance() << endl;
            }  
            else   // Penguin purchased
            {
               make_payment(1000);  // Subtract penguin cost from bank
               cout << "Penguin purchased for $1,000. You have $" 
                    << get_bank_balance() << " remaining." << endl;
               add_animal(new Penguin(3)); // Add adult penguin to array
            }
            break;

         case 3:   // Turtle chosen
            if(get_bank_balance() < 100) // If user cant afford turtle
            {
               cout << "You don't have enough money to buy a turtle "
                    << "right now. They cost $100 and you only have $"
                    << get_bank_balance() << endl;
            }  
            else   // Turtle purchased
            {
               make_payment(100);  // Subtract turtle cost from bank
               cout << "Turtle purchased for $100. You have $" 
                    << get_bank_balance() << " remaining." << endl;
               add_animal(new Turtle(3)); // Add adult turtle to array
            }
            break;
      }
   }
   else            // If user chooses not to buy adult animal
   {
      cout << "You have chosen not to buy an adult animal." << endl;
   }
}


/*
* Summary: calc_payoff() - calculates the total payoff from a day from
*          all the animals
* Returns: total payoff for the day
*/
int Zoo::calc_payoff()
{
   int i = 0;                 // Iterator initiated
   int total_payoff = 0;      // Daily payoff reset

   while(tigers[i] != NULL)   //Tiger payoff calculated
   {
      total_payoff += tigers[i]->get_payoff();
      i++;
   }

   i = 0;                     //iterator reset
   while(penguins[i] != NULL) // Penguin payoff calculated
   {
      total_payoff += penguins[i]->get_payoff();
      i++;
   }

   i = 0;                     //iterator reset
   while(turtles[i] != NULL)  // Turtle payoff calculated
   {
      total_payoff += turtles[i]->get_payoff();
      i++;
   }

   return total_payoff;       //Daily total payoff returned
}

/*
* Summary: delete_arrays() - deletes the dynamically allocated arrays
*          that hold the animal objects. First deletes each object pointer
*          that is not NULL in the array, then deletes the array
*/
void Zoo::delete_arrays()
{
   int i = 0;
   while(tigers[i] != NULL)      // Checks tiger array for tigers
   {
      delete tigers[i];          // Deletes any tigers
      i++;
   }
 
   i = 0;
   while(penguins[i] != NULL)    // Checks penguin array for penguins
   {
      delete penguins[i];        // Deletes any penguins
      i++;
   }
  
   i = 0;
   while(turtles[i] != NULL)     // Checks turtle array for turtles
   {
      delete turtles[i];         // Deletes any turtles
      i++;
   }

   delete [] tigers;             // Tiger array deleted
   delete [] penguins;           // Penguin array deleted
   delete [] turtles;            // Turtle array deleted
}
