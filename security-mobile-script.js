Java.perform(function () {
    var target = Java.use('com.example.introductory.introductory.Auth');

    target.authUser.implementation = function (v1, v2, v3, v4, v5) {
       console.log(v1.getPassword(), v2, v3, v4, v5);

       return this.authUser(null);
    };
});
