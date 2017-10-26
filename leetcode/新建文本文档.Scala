import org.apache.spark.rdd.RDD  
  
def computeRMSE(model:MatrixFactorizationModel, data:RDD[Rating]): Double = 
{  
	val usersProducts = data.map(x=>(x.user,x.product))  
	val ratingsAndPredictions = data.map{
		case Rating(user,product,rating)=>((user,product),rating)}
		.join(model.predict(usersProducts)
		.map{case Rating(user,product,rating)=>((user,product),rating)}).values ;
	math.sqrt(ratingsAndPredictions.map(x=>(x._1-x._2)*(x._1-x._2)).mean())
}  