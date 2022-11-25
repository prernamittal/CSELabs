var myApp = angular.module("myModule",[]);
var myController=function($scope,$routeParams)
{
    $scope.firstName="Prerna";
    $scope.lastName="Mittal";
}
myApp.controller("myController",['$scope',myController]);