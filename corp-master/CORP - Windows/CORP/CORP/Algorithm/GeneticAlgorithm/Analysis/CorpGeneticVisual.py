import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import sys
import time

# class to parse and graph lists outputed from corp project

class CorpGeneticVisual():
    
    def __init__(self, input_file_path):
        self._fitnesses = []
        self._cover_percents = []
        self._num_selecteds = []
        self._colors = []
        self.parse(input_file_path)
   
    # parse data from file into lists
    def parse(self,input_file_path):
        
        data_class = 0
        
        with open(input_file_path, 'r') as f:
            
            for line in f:
                
                if len(line) == 1: 
                    data_class = 0
                
                else:
                    if data_class == 0:
                        self._fitnesses.append(eval(line))
                    elif data_class == 1:
                        self._cover_percents.append(eval(line))
                    elif data_class == 2:
                        self._num_selecteds.append(eval(line))
                    elif data_class == 3:
                        self._colors.append(eval(line))
                        
                    data_class+=1
                  
                    
        
    def graphAll(self):
        
        fig = plt.figure()
        
        ax1 = fig.add_subplot(221)
        ax2 = fig.add_subplot(222)
        ax3 = fig.add_subplot(223)
        ax4 = fig.add_subplot(224)
        
        ax1.set_title("Fitness")
        
        ax2.set_title("Colors")
        
        ax3.set_title("Number Selected")
        
        ax4.set_title("Percent Covered")
        
        solution_count = [i for i in range(len(self._fitnesses)*len(self._fitnesses[0]))],
        
        ax1.scatter(solution_count, self._fitnesses,c='black', marker='o')
        
        ax2.scatter(solution_count, self._colors,c='black', marker='o')
        
        ax3.scatter(solution_count, self._num_selecteds,c='black', marker='o')
        
        ax4.scatter(solution_count, self._cover_percents,c='black', marker='o')
        
        plt.tight_layout()
        
        plt.show()
                
    def graph3D(self,x,y,z,x_label,y_label,z_label):
            
        
        fig = plt.figure();
        ax = fig.add_subplot(111, projection='3d');
        generations = [i for i in range(len(self._fitnesses))];
 
        ax.scatter(x,y,z,c='r', marker='o');

        ax.set_xlabel(x_label);
        ax.set_ylabel(y_label);
        ax.set_zlabel(z_label);
        fig.savefig('fig.png');
     

if __name__ == '__main__':
    
    # 0 => All Plots
    # 1 => 3D Plot
    
   
    
    GRAPH_CHOICE = 1
    
    g = CorpGeneticVisual("C:/Users/Steven/Desktop/metrics.txt")

    if GRAPH_CHOICE == 0:
            g.graphAll()
    
    elif GRAPH_CHOICE == 1:
        while(True):
            time.sleep(5)
            g.parse("C:/Users/Steven/Desktop/metrics.txt")
            g.graph3D(g._colors,
                         g._num_selecteds,
                         g._cover_percents,
                         'Colors Used',
                         'Number Selected',
                         'Cover Percent')
        
        
    
        
    
    


                    