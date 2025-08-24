#include <iostream> 
using namespace std; 
 
int main() { 
 
    /*maximum number of students 
    setU= set of all students  
    setA=drama club 
    setB=science club 
    */ 
    int setU[50], setA[50], setB[50]; 
    int m, o, n; 
     
    //input for students in class 
    cout << "Enter total number of students in class: "; 
    cin >> m; 
    cout << "Enter roll numbers of students in the class:\n"; 
    for (int i = 0; i < m; i++) 
        cin >> setU[i]; 
         
    //input for students in Science club 
    cout << "\nEnter number of students in Science Club: "; 
    cin >> n; 
    cout << "Enter roll numbers of students in Science Club:\n"; 
    for (int i = 0; i < n; i++) 
        cin >> setB[i]; 
 
    //input for students in drama club 
    cout << "\nEnter number of students in Drama Club: "; 
    cin >> o; 
    cout << "Enter roll numbers of students in Drama Club:\n"; 
    for (int i = 0; i < o; i++) 
        cin >> setA[i]; 
         
    //printing sets 
    cout << " SetU : " ; 
    for ( int i=0 ; i<m ; i++ ){ 
  cout << " " << setU[i] ; 
 } 
 cout << endl ; 
  
 cout << " SetA : " ; 
    for ( int i=0 ; i<o ; i++ ){ 
  cout << " " << setA[i] ; 
 } 
 cout << endl ; 
  
 cout << " SetB : " ; 
    for ( int i=0 ; i<n ; i++ ){ 
  cout << " " << setB[i] ; 
 } 
 cout << endl ; 
 
    // 1. Students in both clubs (Intersection) 
    cout << "\nStudents in BOTH clubs:\n"; 
    for (int i = 0; i < o; i++) { 
        for (int j = 0; j < n; j++) { 
            if (setA[i] == setB[j]) { 
                cout << setA[i] << " "; 
                break; 
            } 
        } 
    } 
 
    // 2. Students in at least one club (Union) 
    int unionSet[100], size = 0; 
    for (int i = 0; i < n; i++) 
        unionSet[size++] = setB[i]; 
 
    for (int i = 0; i < o; i++) { 
        bool found = false; 
        for (int j = 0; j < n; j++) { 
            if (setA[i] == setB[j]) { 
                found = true; 
                break; 
            } 
        } 
        if (!found) 
            unionSet[size++] = setA[i]; 
    } 
 
    cout << "\n\nStudents in AT LEAST ONE club:\n"; 
    for (int i = 0; i < size; i++) 
        cout << unionSet[i] << " "; 
 
    // 3. Students in Drama club but not in Science (A - B) 
    cout << "\n\nStudents ONLY in Drama Club:\n"; 
    for (int i = 0; i < o; i++) { 
        bool found = false; 
        for (int j = 0; j < n; j++) { 
            if (setA[i] == setB[j]) { 
                found = true; 
                break; 
            } 
        } 
        if (!found) { 
            cout << setA[i] << " "; 
  } 
    } 
     
    // 4. Students in Science club but not in Drama (B - A) 
    cout << "\n\nStudents ONLY in Science Club:\n"; 
    
   for (int i = 0 ; i < n ; i++ ) { 
    bool found = false ; 
    for (int j=0 ; j< o ; j++ ) { 
     if (setB[i] == setA[j]) { 
      found = true ; 
      break ; 
     } 
    } 
    if (!found) { 
     cout << setB[i] << " " ; 
    } 
   } 
 
 
    // 5. Students in neither club ; 
    cout << "\n\nStudents in Neither club :\n"; 
    for ( int i = 0 ; i < m ; i++ ) { 
  bool found = false ; 
  for (int j=0 ; j<size ; j++ ) { 
   if (setU[i] == unionSet[j]) { 
    found = true ; 
    break ; 
   } 
  } 
  if (!found) { 
   cout << setU[i] << " " ; 
  } 
 } 
}