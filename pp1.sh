echo "Menu:
1.Create Employee Record
2.Delete Employee Record
3.Search Employee Record
4.Display Employee Details
5.Sort Records
6.List all Records
7.Exit
Enter Your Choice (1-7): "
read num


 case "$num" in
	1)
		echo "Enter employee's name: "
	        read name
	        echo "Enter employee's ID: "
	        read id
	        echo "Enter employee's salary:"
	        read salary
		echo "$name,$id,$salary" >>employee_records.csv

		echo "Employee details saved successfully."
		;;
	
	2)
	        echo "Enter the name to be deleted: "
		read delname

		temp_file=$(mktemp)
                while IFS=, read -r name id salary
		do
			if [[ "$name" != "$delname" ]];  then
				echo "$name,$id,$salary" >> "$temp_file"
			fi
	 	      done < employee_records.csv
		mv "$temp_file" employee_records.csv
		echo "Emlpoyee record for $delname deleted successfully."
		;;

	3)
                echo "Enter the name of the employee to search: "
	        read namesearch
		found=0
		while IFS=, read -r name id salary
		do
			if [[ "$name" == "$namesearch" ]]; then
			  echo "Employee details:"
			  echo "Name: " $name
			  echo "ID: " $id
			  echo "salary: " $salary
			  found=1
			  break
			fi
		done < employee_records.csv

		if [[ $found -eq 0 ]]; then
			echo "Employee $delname not found."
		fi
		;;


	4) 
                awk 'BEGIN {FS=","; OFS="\t"; print "Name\tId\tSalary"} {print $1, $2, $3, $4}' employee_records.csv
		;;

	5)
		sort -t ',' -k1,1 employee_records.csv
		;;

	6)
		cat employee_records.csv
		echo "Name    | Id   | Salary"
		echo "......................."

		while IFS=, read -r name id salary
		do
		  printf "%-8s| %-4s| %s\n" "$name" "$id" "$salary"
	        done < employee_records.csv
                ;;
        7)
                exit 0
                ;;		

	*)
	        echo "Invalid choice."
		;;


 esac
exit 0

