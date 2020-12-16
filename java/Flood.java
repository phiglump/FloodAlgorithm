/**
 *File: Flood.java
 *This is the completed build for the flood algorithm
 *It will take the info provided in the file and pass it into a Hashmap
 *From there it is parsed to find all of the reachable nodes from the given starting node
 *And lastly it will have any duplicates removed and be sorted and then printed. 
 *@author Philippe Lumpkin
 *@version 2.1
 *@since 2020-04-03
 */

import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

public class Flood {
    /**
     *This simply will just remove the Dups and Sort the list before printing for the user to see. 
     *@param neighbors the list of all of the confirmed reachables
     **/
    public void rmDupsAndSort(List<String> neighbors) {
	List<String> temp = new ArrayList<String>();

	for(String a : neighbors) {
	    if (!temp.contains(a)) {
		temp.add(a);
	    }
	}
	Collections.sort(temp);
	System.out.println(temp);
    }
    /**
     *This function is the parser that goes thru the list by first getting the first set of reachable nodes from 
     *the very start. Essentially jump starting the loop afterwords.
     *It will then make sure that what it will try to check isn't null and also that it isn't in the already 
     *checked nodes, otherwise it would probably end up with loops or redundant checks/info. 
     *If it has passed the if statements it will begin to gather all of the reachable's reachables,
     *and add to the reachable list as it goes until it is finished.
     *@param m this is the map of the edges
     *@param start this is the starting node
     **/
    public void parser(Map<String, List<String>> m, String start) {
	List<String> neighbors = new ArrayList<String>();
	List<String> temp = new ArrayList<String>();
	String checked = "";
	if (m.get(start) != null) {
	    neighbors = m.get(start);
	    
	    for (int i = 0; i < neighbors.size(); i++) {
		if (m.get(neighbors.get(i)) != null) {
		    if (checked.indexOf(neighbors.get(i)) == -1){
			temp = m.get(neighbors.get(i));
			neighbors.addAll(temp);
			checked = checked + neighbors.get(i);
		    }
		}
	    }
	    Flood floodObject3 = new Flood();
	    floodObject3.rmDupsAndSort(neighbors);
	}
	else {
	    System.out.println("The typed in start doesn't exist within in the list.");
	}
    }
    /**
     *This is the method that takes all the input from the given graph file
     *and store all of it into a hash map. This seemed the most appealing to me as it represents the edges conviently
     *@param args the arguments passed into the prgram during execution
     **/
    public void getData(String[] args) {
	try {
	    Scanner inFile = new Scanner(new File(args[0]));
	    String start = args[1];
	    Map<String, List<String>> m = new HashMap<String, List<String>>();
	    while(inFile.hasNext()) {
		String a = inFile.next();
		String b = inFile.next();
		m.putIfAbsent(a, new ArrayList<String>());
		m.get(a).add(b);
	    }
	    inFile.close();
	    Flood floodObject2 = new Flood();
	    floodObject2.parser(m, start);
	}
	catch (FileNotFoundException e) {
	    System.out.println("Error: File " + args[0] + " doesn't exist.");
	    e.printStackTrace();
	}
    }
    
    /**
     *This is the main, or the entry point into the program and it will create an object and call the get data function to begin
     *@param args The single parameter will be the graph 
     */
    public static void main(String[] args) {
	Flood floodObject = new Flood();
	floodObject.getData(args);
    }
}
