var myApp=angular.module("myModule",[]);
var myController=function($scope,$routeParams)
{
    $scope.msg1="Computer Science";
    $scope.msg2="MIT Manipal";
}
myApp.controller("myController",['$scope',myController]);
