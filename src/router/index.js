import Vue from 'vue'
import Router from 'vue-router'
import NHL321 from '@/components/NHL321'

Vue.use(Router)

export default new Router({
  mode: 'history',
  routes: [
    {
      path: '/',
      name: 'NHL321',
      component: NHL321
    }
  ]
})
