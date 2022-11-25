var myApp=angular.module("myModule",[]);
var myController=function($scope,$routeParams)
{
    $scope.string="QwErTy";
}
myApp.controller("myController",['$scope',myController]);
