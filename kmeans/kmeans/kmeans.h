

// DEFINES
#define         SUCCESS         1
#define         FAILURE         0
#define         TRUE            1
#define         FALSE           0
#define         MAXVECTDIM      20
#define         MAXPATTERN      20
#define         MAXCLUSTER      10

// ***** Defined structures & classes *****
struct aCluster {
	double       Center[MAXVECTDIM];
	int          Member[MAXPATTERN];  //Index of Vectors belonging to this cluster
	int          NumMembers;
};

struct aVector {
	double       Center[MAXVECTDIM];
	int          Size;
};

class System {
private:
	double       Pattern[MAXPATTERN][MAXVECTDIM+1];
	aCluster     Cluster[MAXCLUSTER];
	int          NumPatterns;          // Number of patterns
	int          SizeVector;           // Number of dimensions in vector
	int          NumClusters;          // Number of clusters
	void         DistributeSamples();  // Step 2 of K-means algorithm
	int          CalcNewClustCenters();// Step 3 of K-means algorithm
	double       EucNorm(int, int);   // Calc Euclidean norm vector
	int          FindClosestCluster(int); //ret indx of clust closest to pattern
	//whose index is arg
public:
	//system();
	int LoadPatterns(char *fname);      // Get pattern data to be clustered
	void InitClusters();                // Step 1 of K-means algorithm
	void RunKMeans();                   // Overall control K-means process
	void ShowClusters();                // Show results on screen
	void SaveClusters(char *fname);     // Save results to file
	void ShowCenters();
};