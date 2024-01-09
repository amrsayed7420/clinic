    #include <stdio.h>
    #include <stdlib.h>


    typedef struct patient
    {
    char                name[20]                ;
    int                 age                     ;
    char                gender[10]              ;
    int                 id                      ;
    struct patient  *   next                    ;
    int                 reservation_flag        ;
    char                *slot                   ;  

    }patient ;


    typedef struct clinc
    {
        patient * top ;
    }clinc;


    void clinc_voidInit (clinc * ps )
    {
    ps->top = NULL ;
    }






    int    slot_status[5]={0,0,0,0,0};
    int *  slots[5]={"1- 2pm to 2:30pm","2- 2:30pm to 3pm","3- 3pm to 3:30pm","4- 4pm to 4:30pm","5- 4:30pm to 5pm"};


    void Add_new_patient_record (clinc * ps)                ;//
    void Edit_patient_record (clinc * ps )                  ;//
    void display_patient_record (clinc * ps)                ;//   
    void display_patient_record_for_user (clinc * ps)       ;//


    void avail_reserveSlot  (clinc * ps)                    ;//
    void reserveSlot  (clinc * ps)                          ;
    void display_reservation_record (clinc * ps)            ;
    void cancelReservation (clinc * ps)                     ;




/************************************************************************************************************************/
    void Add_new_patient_record (clinc * ps)
    {
            patient  * Pn   =   (patient *)malloc(sizeof(patient))    ;
            patient * current = ps->top     ;
            int ID ;
            int flag =0 ;


            

                do
                {   flag = 0 ;
                    printf("Enter Id Of User : \n" );   
                    
                    if (1 != scanf ("%d",&ID)) 
                    {
                        printf("out of range");  
                        break; 
                    }

                    current = ps->top;
                    
                    while (current != NULL)
                    {


                        if(ID == current->id)
                        {
                        printf("Error: ID already exists.\n");
                        //printf("flag= %d\n",flag );

                        flag ++  ;
                        //printf("flag= %d\n",flag );

                        //  printf("Renter the data \n" );
                        // Add_new_patient_record (&ps)    ;
                        }

                        current = current -> next ;

                    } 


                } while( flag != 0 );
            
            

            if(flag==0)
            {
            Pn -> id  = ID ;

            printf("Enter Name Of The User : \n" );
            scanf ("%s",&Pn -> name);
            //  gets (&Pn -> name);

            printf("Enter Age Of User : \n" );
            scanf ("%d",&Pn -> age);

            printf("Enter Gender Of User : \n" );
            scanf ("%s",&Pn -> gender);

            Pn ->slot = ""  ;
            
            Pn ->reservation_flag = -1  ;

            Pn-> next = ps -> top ;
            ps -> top = Pn ;
            printf("\n");

            }

        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

    }


/************************************************************************************************************************/
    void display_patient_record (clinc * ps)
    {
        patient * current = ps->top;

        while (current != NULL)
        {
        printf(" Name Of User : %s \n",current -> name  );

        printf(" Age Of User : %d \n",current -> age );

        printf(" Gender Of User : %s \n",current -> gender  );

        printf(" Id Of User : %d \n",current -> id );

        printf("%s \n",current -> slot  );


        current = current -> next ;

        printf("\n");


        }

        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

    }


/************************************************************************************************************************/
    void display_patient_record_for_user (clinc * ps)
    {
        patient * current = ps->top;
        int ID ;
        int flag_id=0  ;
          printf(" Enter The Id Of User " )          ;
          scanf ("%d",&ID )                           ;
        while (current != NULL)
        {
            if (current->id == ID)
        { flag_id ++ ;
          printf(" Name Of User : %s \n",current -> name  );

          printf(" Age Of User : %d \n",current -> age );

          printf(" Gender Of User : %s \n",current -> gender  );

          printf(" Id Of User : %d \n",current -> id );

          printf("%s \n",current -> slot  );
        }

        current = current -> next ;

        }

        printf("\n");

        if (flag_id ==0)
    {
        printf("Wrong Id \n" );

    }



        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }



/************************************************************************************************************************/
    void display_reservation_record (clinc * ps)
    {
        patient * current = ps->top;

        while (current != NULL)
        {
            if (current -> reservation_flag != -1)
            {
            printf(" Name Of User : %s \n",current -> name  );

            printf(" Age Of User : %d \n",current -> age );

            printf(" Gender Of User : %s \n",current -> gender  );

            printf(" Id Of User : %d \n",current -> id );

            printf("%s \n",current -> slot  );
            }


        current = current -> next ;

        }

        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }


/************************************************************************************************************************/
    void reserveSlot  (clinc * ps)
    {

    patient * current = ps->top   ;
    int ID ;
    int flag_id=0  ;
    int index = 0   ;
    printf(" Enter The Id Of User " )          ;
    scanf ("%d",&ID )          ;


    while(current != NULL)
    {

        if (current->id == ID)
        { flag_id ++ ;


        for(int i=0 ; i<5 ;i++)
        {
            if(slot_status[i]== 0)  
            {
                printf("%s\n",slots[i]) ;
            }

        }
        //  printf("\n1- 2pm to 2:30pm . \n2- 2:30pm to 3pm. \n3- 3pm to 3:30pm. \n4- 4pm to 4:30pm.\n5- 4:30pm to 5pm\nSlot NUMBER: ");

        scanf ("%d",&index )          ;

            if(slot_status[index-1]== 0)  
            {

            switch (index)
            {
            case 1:    slot_status[index-1]=1 ;
                        current -> slot ="2pm to 2:30pm"     ; 
                        current -> reservation_flag =  0     ;    


                break;
            case 2:    slot_status[index-1]=1 ;
                        current -> slot ="2:30pm to 3pm" ;  
                        current -> reservation_flag =  1     ;    
    
                break;
                
            case 3:    slot_status[index-1]=1 ;
                        current -> slot ="3pm to 3:30pm" ; 
                        current -> reservation_flag =  2     ; 
                break;

            case 4:    slot_status[index-1]=1 ;
                        current -> slot ="4pm to 4:30pm" ;   
                        current -> reservation_flag =  3     ;   
                break;

            case 5:    slot_status[index-1]=1 ;
                        current -> slot ="4:30pm to 5pm" ; 
                        current -> reservation_flag =  4     ;     
                break;
            default:          printf("Wrong Entering !");

                break;
            }

            }

            else 
            {
                printf("already reserved \n")   ;
            }

        }
        current = current -> next ;


    }

    if (flag_id ==0)
    {
        printf("Wrong Id \n" );

    }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }


/************************************************************************************************************************/
 void avail_reserveSlot  (clinc * ps)
    {
        for(int i=0 ; i<5 ;i++)
        {
            if(slot_status[i]== 0)  
            {
                printf("%s\n",slots[i]) ;
            }

        }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }



/************************************************************************************************************************/

    void cancelReservation (clinc * ps)
    {   


display_reservation_record (ps) ;



    patient * temp = ps->top   ;
    int ID ;
    int flag_id=0  ;
    printf(" Enter The Id Of User " )          ;
    scanf ("%d",&ID )          ;


    while(temp != NULL)
    {


        if (temp->id == ID)
        { flag_id ++ ;

            if(temp->reservation_flag != -1)
            {


                slot_status[temp->reservation_flag]=0 ;
                temp -> slot = "" ; 
                temp -> reservation_flag =  -1     ;     


            printf("The reservation has been cancelled  \n" );

            }
            else
            {
            printf("Not reserved \n" );
            }

        }
        temp = temp -> next ;


    }

    if (flag_id == 0)
    {
        printf("Wrong Id \n" );

    }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }



/************************************************************************************************************************/
    void Edit_patient_record (clinc * ps )
    {
    patient * current = ps->top   ;
    int ID ;
    int flag=0  ;
    printf(" Enter Id " )          ;
    scanf ("%d",&ID )          ;


    while(current != NULL)
    {

        if (current->id == ID)
        { flag++ ;
            printf("Enter Name Of User : \n" );
            scanf ("%s",&current -> name);

            printf("Enter Age Of User : \n" );
            scanf ("%d",&current -> age);

            printf("Enter Gender Of User : \n" );
            scanf ("%s",&current -> gender);

           // printf("Enter Id Of User : \n" );
            //scanf ("%d",&current -> id);

            break ;
        }
        current = current -> next ;


    }
    if (flag ==0)
    {
        printf("Wrong id \n" );

    }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");



    }


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

int main()
{
    int mode ;
    int password =1234 ;
    int enterd_password = 0 ;

    int select ;
    int correct_login  ;

    clinc clinic1 ;
    clinc_voidInit (&clinic1) ;


    while (1)
    {
        correct_login = 0    ;
        select = 0           ;

        printf("enter the mode you want \n") ;
        printf("admin mode press 1\n") ;
        printf("user mode press 2\n") ;


        if (1 != scanf ("%d",&mode)) 
        {                   
            printf("out of range\n");  
            break; 
        }



        switch (mode)
        {

        case 1 :

            for (int i= 0 ; i<3  ; i++ )
            {
                printf(" Enter the password: \n");
                scanf("%d",&enterd_password);
                if ( password == enterd_password )
                {
                    printf("correct password \n");
                    correct_login = 1  ;
                    break ;
                }

                else
                {
                    printf("incorrect password , you have %d tries \n",2-i);

                }


            }

            if (correct_login != 1 ) return  ;


            else
            {              
                while ( select != 9 )
                {


                    printf("1-Add_new_patient_record\n") ;
                    printf("2-Edit_patient_record\n") ;
                    printf("3-reserveSlot\n") ;
                    printf("4-cancelReservation\n") ;
                    printf("5-display_patient_record\n") ;
                    printf("6-display_reservation_record\n") ;
                    printf("7-display_patient_record_for_user\n") ;
                    printf("8-avail_reserveSlot\n") ;
                    printf("9-Back\n") ;
 
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("\n");

        
                    scanf ("%d",&select);


                    switch (select)
                    {
                        case 1 :  Add_new_patient_record (&clinic1)  ;
                        break;

                        case 2 :  Edit_patient_record (&clinic1)  ;
                        break;

                        case 3 :  reserveSlot (&clinic1)  ;
                        break;

                        case 4 :  cancelReservation (&clinic1)  ;
                        break;
        
                        case 5 :  display_patient_record (&clinic1)  ;
                        break;

                        case 6 :  display_reservation_record (&clinic1)  ;
                        break;
        
                        case 7 :  display_patient_record_for_user (&clinic1)  ;
                        break;

                        case 8 :  avail_reserveSlot (&clinic1)  ;
                        break;

                        case 9 :  
                        break;

                        default:          printf("Wrong Entering ! \n");
                        break;
                    }


                }

            }


        break;


        case 2 :
        {
            printf("this user mode \n") ;
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");

            select  =   0   ;

            while ( select != 3 )
            {



                printf("1-display_patient_record_for_user\n") ;
                printf("2-avail_reserveSlot\n") ;

                printf("3-Back\n") ;

                printf("\n");
                printf("\n");
                printf("\n");
                printf("\n");

        
                scanf ("%d",&select);


                switch (select)
                {
                    case 1 :  display_patient_record_for_user (&clinic1)  ;
                    break;

                    case 2 :  avail_reserveSlot (&clinic1)  ;
                    break;


                    case 3 :  
                    break;

                    default:          printf("Wrong Entering !");
                    break;
                }


            }


        }


        break;


        default :   printf("no mode by this value \n") ;
        break;

        }

    }
       
    return 0;

}
