var myApp=angular.module("myModule",[]);
myApp.controller("myController",['$scope',function($scope,$routeParams){
    $scope.tutorial={"tutorialID":52,"tutorialName":"AngularJS"};
}]);
