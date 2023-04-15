During sequencing, the sample DNA is broken into many pieces that are sequenced in parallel. After that, a computer must put the pieces back in order by aligning matching sequences at the ends of the pieces. Bowtie2 is a short read alignment tool that is used to align sequences to reference genomes often used in genomics research. It is a staple in many assembly and annotation workflows. Note that the program is bowtie2 even though the naming convention on the HPCC refers to it as bowtie. They are different with different uses and syntax. Bowtie is for reads shorter than 50 base pairs and only supports ungapped mapping. Bowtie2 allows for gapping in its mapping and higher sensitivity to reads longer than 50bp compared to bowtie. It's not the end of the world if you use the wrong one, but it has the potential to give you funny results depending on what you're looking at.

If you would like a more in depth comparison of bowtie vs bowtie2 as well as some other alignment tools, see this article. https://merenlab.org/2015/06/23/comparing-different-mapping-software/

Bowtie2 is already installed on the HPCC. To load the example code, we will be using getexample from the powertools module.

1. Load the powertools module by running the following line:
module load powertools
2. Download the bowtie2 example
getexample bowtie
3. Run the example
qsub bowtie.qsub
