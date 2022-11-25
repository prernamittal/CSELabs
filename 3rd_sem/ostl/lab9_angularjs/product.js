var myApp = angular.module("myModule",[]);
var myController=function($scope,$routeParams)
{
    $scope.Price=0;
    $scope.Quantity=0;
}
myApp.controller("myController",['$scope',myController]);